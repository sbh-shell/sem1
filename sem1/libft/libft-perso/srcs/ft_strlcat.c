/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:30:21 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:25:14 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	t_uint		i;
	t_uint		j;

	i = MAX_UINT;
	while (dst[++i] && size)
		size--;
	if (!size)
		return (i + ft_strlen(src));
	len = i;
	j = MAX_UINT;
	while (src[++j])
		if (size > 1)
		{
			dst[i++] = src[j];
			--size;
		}
	dst[i] = '\0';
	return (len + j);
}
