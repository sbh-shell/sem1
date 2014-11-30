/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 06:52:22 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 19:59:04 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_init_expr(t_expr *expr) // -1 est l'absence de champs ds l'expr
{
	size_t		i;

	i = 0;
	while (i < 5)
		expr->flag[i++] = FALSE;
	expr->length = 0;
	expr->width = 0;
	expr->precision = 0;
}
