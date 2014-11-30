/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 08:11:48 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/29 10:29:30 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;

	ret = ft_printf("1 : %d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("2 : %d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("3 : % d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("4 : % d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("5 : %+ d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("6 : %+ d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("7 : %+ 10d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("8 : %+ 10d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("9 : %3d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("10 : %3d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("11 : % 10d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("12 : % 10d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("13 : %+ -10d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("14 : %+ -10d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("15 : %+ -10.5d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("16 : %+ -10.5d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("17 : %-+10.6d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("18 : %+-10.6d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("19 : % 10.15d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("20 : % 10.15d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("21 : %+ -10.15d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("22 : %+ -10.15d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("23 : %+ -0.0d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	ret = ft_printf("24 : %+ -0.0d\n", -42000000);
//	printf("ret = %d\n\n", ret);
	
	ret = ft_printf("25 : %-+10.6hd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("26 : %+-10.6hd\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("27 : % 10.15hhd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("28 : % 10.15hhd\n", -42000000);
//	printf("ret = %d\n\n", ret);
/*
	ret = ft_printf("29 : %+ -10.15zd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("30 : %+ -10.15zd\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("31 : %+ -0.0jd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = ft_printf("32 : %+ -0.0jd\n", -42000000);
//	printf("ret = %d\n\n", ret);
*/
	return (0);
}
