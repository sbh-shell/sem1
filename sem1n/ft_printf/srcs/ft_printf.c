/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-vgr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:26:07 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 19:47:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//IDEE OPTI : DON'T CHECK EACH REGULAR EXPR (ADD ATTRIBUT TO DON'T COMPIL IF THEY'RE WRONG )

#include "ft_printf.h"

static int			ft_check_expr(char *format, size_t *i, va_list *va)
{
	t_expr		expr;
	int			len;
	
	len = 0;
	(*i)++; //MAYBE HAVE TO REMOVE IF ADD BETWEEN TWO FIRST IF IN READ FUNCTION
	ft_init_expr(&expr); //HAVE TO CHECK MALLOC RETURN !!!!!!!!!!!
		//return (-1);
	if (ft_check_flag(format, i, &expr) < 0)
		return (-1);
	if (ft_check_width(format, i, &expr) < 0)
		return (-1);
	if (ft_check_precision(format, i, &expr) < 0)
		return (-1);
	if (ft_check_length(format, i, &expr) < 0)
		return (-1);
	len = ft_apply_to_specifier(va, format, i, &expr); //HAVE TO CALL APPLY IN PFINCIPAL FUNCTION (PRINTF)
	return (len);
}

static int			ft_read_format(char *format, va_list *va)
{
	size_t		i;
	int			len;
	int			ret;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			//++i; //ANNUL SI RAJOUT EN DEBUT DE CHECK EXPR
			if ((ret = ft_check_expr(format, &i, va)))
			{
				len += ret;
				++i;
			}
		}
		ft_putchar(format[i]);
		if (format[i])
		{
			++len;
			++i;
		}
	}
	return (len);
}

int			ft_printf(char *format, ...)
{
	va_list			va;
	int				len;

	len = 0;
	if (!format)
		return (-1);
	va_start(va, format);
	len = ft_read_format(format, &va);
	va_end(va);
	return (len);
}
