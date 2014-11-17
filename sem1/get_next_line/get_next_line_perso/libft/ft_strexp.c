/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 04:33:17 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 04:33:22 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strexp(char *s, size_t size)
{
	char		s_tmp[size];

	if (!s || size < ft_strlen(s))
		return (NULL);
	strncpy(s_tmp, s, size);
	free(s);
	if (!(s = malloc(sizeof(size))))
		return (NULL);
	s = strncpy(s, s_tmp, size);
	return (s);
}
