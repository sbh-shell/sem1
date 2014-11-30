/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:30:23 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/29 04:34:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_length_d(va_list *va, t_expr *expr)
{
	long long int	arg;

	if (!expr->length)
		arg = va_arg(*va, int);
	else if (expr->length == SCHAR)
		arg = (signed char)va_arg(*va, int);
	else if (expr->length == SHORT)
		arg = (short)va_arg(*va, int);
	else if (expr->length == LINT)
		arg = va_arg(*va, long int);
	else if (expr->length == LLINT)
		arg = va_arg(*va, long long int);
	else if (expr->length == IMAX)
		arg = va_arg(*va, intmax_t);
	else if (expr->length == SSIZE)
		arg = va_arg(*va, ssize_t);
	return (arg);
}

size_t		ft_nbr_digit(long long int nbr)
{
	size_t		i;

	ABS(nbr);
	i = 1;
	while (nbr > 9)
	{
		++i;
		nbr /= 10;
	}
	return (i);
}

char		*ft_fill(int c, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
		str[i++] = c;
	return (str);
}

int		ft_aff_d(long long int arg, t_expr *expr, char *width, char *precision)
{
	int			ret;
	char		none;

	none = 0;
	ret = 0;
	if ((expr->flag[ESCAPE] || expr->flag[PLUS]) && (arg > 0))
	{
		++ret;
		if (expr->flag[PLUS])
			!expr->width ? ft_putchar('+') : none++;
		else
			ft_putchar(' ');
	}
	expr->flag[MINUS] ? /*ft_putstr(precision)*/none++ : ft_putstr(width);
	(expr->width && arg > 0 && expr->flag[PLUS]) ? ft_putchar('+') : none++;
	(arg < 0 && expr->precision) ? ft_putchar('-') : none++ ;
	ft_putstr(precision);
	expr->precision ? ft_putnbr(ABS(arg)) : ft_putnbr(arg);
	expr->flag[MINUS] ? ft_putstr(width) : none++;
	return (ret);
}

int			ft_treat_d(va_list *va, t_expr *expr)
{
	long long int		arg;
	char				*width;
	char				*precision;
	int					ret;
	size_t				nbr_d;

	width = NULL;
	precision = NULL;
	if (!expr)
		return (0);
	arg = ft_length_d(va, expr);
	nbr_d = ft_nbr_digit(arg);
	if (expr->precision)
	{
		if (!(precision = ft_fill('0', expr->precision - nbr_d)))
			return (-1);
	}
	if (expr->width)
	{
		if (!(width = ft_fill(' ', expr->width - expr->precision - nbr_d - ((((expr->flag[PLUS] || expr->flag[ESCAPE]) && arg > 0) || (arg < 0)) ? 1 : 0))))
			return (ft_memdel((void **)&precision), -1);
	}
	ret = ft_aff_d(arg, expr, width, precision) + arg < 0 ? 1 : 0;
	return (ret + ft_strlen(ft_itoa(arg)) + ft_strlen(width) + (ft_strlen(precision) * 2 - 1));
}


int			ft_treat_u(va_list *va, t_expr *expr)
{
	t_uint		arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, t_uint);
	ft_putnbr(arg);
	return (ft_strlen(ft_itoa(arg)));
}

int			ft_treat_i(va_list *va, t_expr *expr)
{
	t_uint		arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, t_uint);
	ft_putnbr(arg);
	return (ft_strlen(ft_itoa(arg)));
}


