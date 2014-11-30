/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:41:08 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/27 18:43:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_natoi(const char *str, size_t n)
{
	size_t			i;
	long			res;
	unsigned int	neg;

	neg = 0;
	res = 0;
	i = 0;
	if (str[i] == '-')
	{
		++i;
		++neg;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]) && n--)
		res = res * 10 + (str[i++] - '0');
	if ((int)res == 0 && res != 0)
		return (neg) ? 0 : -1;
	if (neg)
		return ((int)-res);
	return ((int)res);
}
