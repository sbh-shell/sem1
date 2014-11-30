/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:42:10 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/22 21:42:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puterr.h"

void		puterropt(char *bad_opt)
{
	ft_puterrstr(TITLE);
	ft_puterrstr(ILLEGAL_OPT);
	ft_puterrendl(bad_opt);
	ft_puterrendl(USAGE);
}

void		puterrdir(char *bad_dir)
{
	ft_puterrstr(TITLE);
	ft_puterrstr(bad_dir);
	ft_puterrstr(": ");
	ft_puterrendl(NO_DIR);
}
