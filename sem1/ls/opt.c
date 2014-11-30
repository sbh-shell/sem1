/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 22:17:27 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/22 23:40:44 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_opt		*alloc_opt(void)
{
	t_opt		*opt;
	t_uint		i;

	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	ft_bzero(opt->strict, sizeof(int) * MAX_STRICT);
	opt->optional = NULL;
	return (opt);
}

char		treat_strict_opt(t_opt *opt, int ac, char **av)
{
	t_uint		i;
	t_uint		j;

	i = 0;
	j = 0;
	opt->i_str = 0;
	while (++i <= MAX_STRICT && av[i] && av[i][0] == '-')
	{
		while (av[i][++j])
		{
			if (av[i][j] == 'a')
				++(opt->strict[0]);
			else if (av[i][j] == 'l')
				++(opt->strict[1]);
			else if (av[i][j] == 'r')
				++(opt->strict[2]);
			else if (av[i][j] == 'R')
				++(opt->strict[3]);
			else
				return (puterropt(&(av[i][j])), 0);
		}
		j = 0;
		++(opt->i_str);
	}
	return (1);
}

char		treat_optional_opt(t_opt *opt, char **av)
{
	t_list		*elem;

	if (!(av[opt->i_str + 1]))
	{
		if (!(elem = ft_lstnew((void *)".", sizeof(char) * 2)))
			return (0);
		ft_lstadd_back(&(opt->optional), elem);
	}
	else
	{
		opt->i_opt = 0;
		while (av[++(opt->i_opt) + opt->i_str])
		{
			if (!(elem = ft_lstnew((void *)av[opt->i_opt + opt->i_str], sizeof(char) * ft_strlen(av[opt->i_opt + opt->i_str]) + 1)))
				return (0);
			ft_lstadd_back(&(opt->optional), elem);
		}
		--(opt->i_opt);
	}
	return (1);
}

t_opt		*init_opt(int ac, char **av)
{
	t_opt		*opt;

	if (!(opt = alloc_opt()))
		return (NULL);
	if (!(treat_strict_opt(opt, ac, av)))
		return (NULL);
	i/*if (!(alpha_sort(av)))
		return (NULL);*/
	if (!(treat_optional_opt(opt, av)))
		return (NULL);
	return (opt);
}
