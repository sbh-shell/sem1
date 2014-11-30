/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 14:56:27 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/29 10:29:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		ret;

	ret = printf("1 : %d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("2 : %d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("3 : % d\n", 420000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("4 : % d\n", -420000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("5 : %+ d\n", 42000000);
//	printf("ret = %d\n\n", ret);
	
	ret = printf("6 : %+ d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("7 : %+ 10d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("8 : %+ 10d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("9 : %3d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("10 : %3d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("11 : % 10d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("12 : % 10d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("13 : %+ -10d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("14 : %+ -10d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("15 : %+ -10.5d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("16 : %+ -10.5d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("17 : %-+10.6d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("18 : %+-10.6d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("19 : % 10.15d\n", 42000000);
///	printf("ret = %d\n\n", ret);

	ret = printf("20 : % 10.15d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("21 : %+ -10.15d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("22 : %+ -10.15d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("23 : %+ -0.0d\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("24 : %+ -0.0d\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("25 : %-+10.6hd\n", 42000000);
///	printf("ret = %d\n\n", ret);

	ret = printf("26 : %+-10.6hd\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("27 : % 10.15hhd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("28 : % 10.15hhd\n", -42000000);
//	printf("ret = %d\n\n", ret);
/*
	ret = printf("29 : %+ -10.15zd\n", 42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("30 : %+ -10.15zd\n", -42000000);
//	printf("ret = %d\n\n", ret);

	ret = printf("31 : %+ -0.0jd\n", 42);
//	printf("ret = %d\n\n", ret);

	ret = printf("32 : %+ -0.0jd\n", -42);
//	printf("ret = %d\n\n", ret);*/

	return (0);
}
