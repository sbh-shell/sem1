/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 00:42:53 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 15:27:32 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uint		i;

	i = MAX_UINT;
	while (++i < n)
		if (((t_uchar *)s)[i] == (t_uchar)c)
			return ((void *)(&((t_uchar *)s)[i]));
	return (NULL);
}
