/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_oxp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 04:32:07 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/29 04:33:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_treat_p(va_list *va, t_expr *expr)
{
	void		*arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, void *);
	ft_putstr("0x");
	ft_putstr((char *)arg);
	return (ft_strlen((char *)arg));
}

int			ft_treat_o(va_list *va, t_expr *expr)
{
	t_uint		arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, t_uint);
	ft_putnbr(arg);
	return (ft_strlen(ft_itoa(arg)));
}

int			ft_treat_x(va_list *va, t_expr *expr)
{
	t_uint		arg;

	if (!expr)
		return (0);
	arg = va_arg(*va, t_uint);
	ft_putnbr(arg);
	return (ft_strlen(ft_itoa(arg)));
}

