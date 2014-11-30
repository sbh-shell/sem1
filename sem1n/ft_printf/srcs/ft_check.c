/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 21:25:22 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 20:10:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_flag(char *format, size_t *i, t_expr *expr)
{
	char		none;

	while (format[*i])
	{
		if (!(none = 0) && format[*i] == '#')
			expr->flag[SHARP] = TRUE;
		else if (format[*i] == '+')
		{
			expr->flag[PLUS] = TRUE;
			expr->flag[SPACE] = FALSE;
		}
		else if (format[*i] == '-')
		{
			expr->flag[MINUS] = TRUE;
			expr->flag[ZERO] = FALSE;
		}
		else if (format[*i] == ' ')
			expr->flag[PLUS] == FALSE ? expr->flag[SPACE] = TRUE : none++;
		else if (format[*i] == '0')
			expr->flag[MINUS] == FALSE ? expr->flag[ZERO] = TRUE : none++;
		else
			return (0);
		++(*i);
	}
	return (-1);
}

int			ft_check_width(char *format, size_t *i, t_expr *expr) // LA TAILL EST ELLE EN INT OU PLUS GROSSE? // PASSONS NOUS DE MALLOC // FT_NATOI HEHE
{
	size_t			j;

	j = 0;
	while (format[*i] && ft_isdigit(format[*i]))
	{
		++j;
		++(*i);
	}
	if (j)
		expr->width = ft_atoi(format + (*i - j)); //maybe use natoi with j like size
	return (format[*i] ? 0 : -1);
}

int			ft_check_precision(char *format, size_t *i, t_expr *expr) // IDEm QUE POUR LA TAILLE // . SANS DIGIT QUE PASS?
{
	size_t			j;

	j = 0;
	if (format[*i] != '.')
		return (0);
	++(*i);
	/*while (format[*i] && !ft_isdigit(format[*i]))
		++(*i);*/
	while (format[*i] && ft_isdigit(format[*i]))
	{
		++j;
		++(*i);
	}
	if (j)
		expr->precision = ft_atoi(format + (*i - j));
	return (format[*i] ? 0 : -1);
}

int			ft_check_length(char *format, size_t *i, t_expr *expr)
{
//	if (format[*i]) //since check functions return -1
//	{
	if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
			expr->length = SCHAR;
		else
			expr->length = SHORT;
	}
	else if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
			expr->length = LLINT;
		else
			expr->length = LINT;
	}
	else if (format[*i] == 'j')
		expr->length = IMAX;
	else if (format[*i] == 'z')
		expr->length = SSIZE;
	else
		return (0);
//	}
	*i += (expr->length == SCHAR || expr->length == LLINT) ? 2 : 1;
	return (format[*i] ? 0 : -1);
}

int			ft_apply_to_specifier(va_list *va,  char *format, size_t *i, t_expr *expr)
{ //HAVE TO GRP ALL SIMILAR CASE
	int			len;

	//	if (format[*i])
//	{
	len = 0;
	if (format[*i] == 's')
		len = ft_treat_s(va, expr);
	else if (format[*i] == 'p')
		len = ft_treat_p(va, expr);
	else if (format[*i] == 'd' || format[*i] == 'i')
		len = ft_treat_d(va, expr);
	else if (format[*i] == 'o')
		len = ft_treat_o(va, expr);
	else if (format[*i] == 'u')
		len = ft_treat_u(va, expr);
	else if (format[*i] == 'x')
		len = ft_treat_x(va, expr);
	else if (format[*i] == 'c')
		len = ft_treat_c(va, expr);
	//else
	//	return (0);
//	}
	return (len);
}
