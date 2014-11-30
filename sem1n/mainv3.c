/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:45:14 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/28 13:58:50 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void		main()
{
	int ret;
	char	*test;
/*
	ret = ft_printf("ABC%+22.3d\n%#++++-.4s\n%u\n%#32..64d\n%%\n", 42, "DEF", 42, 42);
	printf("ret = %d\n", ret);
	ret = printf("ABC%d\n%s\n%u\n%#32..64d\n%%\n", 42, "DEF", 42, 42);
	printf("ret pf  = %d\n", ret);
	ret = ft_printf("ABC%+22.3d\n", 42);
	printf("ret = %d\n", ret);
	ret = ft_printf("%#++++-.4s\n", "DEF");
	printf("ret = %d\n", ret);
	ret = ft_printf("%u\n", 42);
	printf("ret = %d\n", ret);*/
	ret = ft_printf("%#32..64d\n", 42);
	printf("ret = %d\n", ret);
/*	ret = ft_printf("%%\n", 42);
	printf("ret = %d\n", ret);*/
	ret = printf("%#32..64d\n", 42);
	printf("ret pf = %d\n", ret);
/*	ret = printf("%#32d\n", 42);
	printf("ret pf = %d\n", ret);*/
}
