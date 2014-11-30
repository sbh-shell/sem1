/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:30:23 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 20:07:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		++i;
	}
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


///////////////////////////////////////////////////////*****LIB*****//////////////////////////////////////////////////

void			ft_aff_d(t_llint arg, t_expr *expr, char **builtin, char c)
{
	char		none;

	none = 0;
	if (expr->flag[MINUS])
	{
		c ? ft_putchar(c) : none++;
		builtin[PRECISION] ? ft_putstr(builtin[PRECISION]) : none++;
		/*ft_putllint(ft_llitoa(arg));*/builtin[PRECISION] ? ft_putnbr(ABS(arg)) : ft_putnbr(arg);
		builtin[WIDTH] ? ft_putstr(builtin[WIDTH]) : none++;
	}
	else
	{
		builtin[WIDTH] ? ft_putstr(builtin[WIDTH]) : none++;
		c ? ft_putchar(c) : none++;
		builtin[PRECISION] ? ft_putstr(builtin[PRECISION]) : none++;
		/*ft_putllint(ft_llitoa(arg));*/builtin[PRECISION] ? ft_putnbr(ABS(arg)) : ft_putnbr(arg);
	}
}

void			ft_build_d(t_llint arg, t_expr *expr, size_t nb_d)
{
	char		*builtin[2];
	char		c;

	c = '\0';
	builtin[PRECISION] = NULL;
	builtin[WIDTH] = NULL;
	if (expr->precision > nb_d)
		builtin[PRECISION] = ft_fill('0', 1 + expr->precision - nb_d);
	if (arg < 0 || (arg > 0 && (expr->flag[SPACE] || expr->flag[PLUS])))
	{
		if (arg < 0 && expr->precision)
			c = '-';
		else if (arg > 0)
			if ((c = ' ') && expr->flag[PLUS])
				c = '+';
	}
	if (expr->width > nb_d && expr->width > expr->precision)
	{
		//(expr->flag[MINUS] && expr->precision) ? expr->width-- : (expr->width = expr->width + 0);
		builtin[WIDTH] = ft_fill(' ', expr->width - ((expr->precision > nb_d) ? expr->precision : nb_d));
	}
	ft_aff_d(arg, expr, builtin, c);
}

size_t			ft_treat_d(va_list *va, t_expr *expr)
{
	size_t			nb_d;
	size_t			len;
	t_llint			arg;

	len = 0;
	arg = ft_length_d(va, expr);
	nb_d = ft_nbr_digit(arg);
	//printf("EXPR :\n\n FLAG :\nSHARP = %d\nZERO = %d\nSPACE = %d\nPLUS = %d\nMINUS = %d\n\nWIDTH = %d\nPRECISION = %d\nLENGTH = %d\n\n", expr->flag[SHARP], expr->flag[ZERO], expr->flag[SPACE], expr->flag[PLUS], expr->flag[MINUS], (int)expr->width, (int)expr->precision, expr->length);
	if ((expr->flag[SPACE] || expr->flag[PLUS]) && arg > 0)
		nb_d++;
	len = (expr->width > nb_d) ? expr->width : nb_d;
	len = (expr->precision > len) ? expr->precision : len;
	len += ((expr->flag[SPACE] || expr->flag[PLUS]) && (expr->precision > expr->width)) ? 1 : 0;
	ft_build_d(arg, expr, nb_d);
	return (len);
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


