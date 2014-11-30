/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:33:37 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/29 04:34:08 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_treat_c(va_list *va, t_expr *expr)
{
	t_uint		arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, int);
	ft_putchar(arg);
	return (arg ? 1 : 0);
}

int			ft_treat_s(va_list *va, t_expr *expr)
{
	char		*arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, char *);
	ft_putstr(arg);
	return (ft_strlen(arg));
}
