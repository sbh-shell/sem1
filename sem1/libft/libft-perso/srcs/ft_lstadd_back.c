/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 20:49:21 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/15 21:04:33 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **alst, t_list *elem)
{
	t_list		*drive;

	if (!elem)
		return ;
	drive = *alst;
	while (drive->next)
		drive = drive->next;
	drive->next = elem;
}
