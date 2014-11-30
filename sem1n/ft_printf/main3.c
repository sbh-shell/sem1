/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 00:26:47 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 20:08:05 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
	//printf("%+30.5d\n", 42);
	ft_printf("% +-0#4.2lld\n", 42);
	ft_printf("%0 .hd\n", 42);
	ft_printf("%d\n", 42);
	ft_printf("%02.0d\n", 42);
	/*ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
	ft_printf("", 42);
*/
	return (0);
}
