/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/28 02:23:48 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 12:23:36 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	t_uint		i;

	i = MAX_UINT;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
