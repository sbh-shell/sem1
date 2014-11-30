/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:26:20 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/22 23:38:01 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	if (!ac || !av)
		return (ft_puterrendl("COMPIL ERR"), -1);

	DIR				*dirp;
	struct dirent	*dir_entry;
	t_opt			*opt;
	t_uint			i;
	t_list			*drive;
	t_list			*tmp;

	if (!(opt = init_opt(ac, av)))
		return (-1);
	i = MAX_UINT;
	drive = opt->optional;
	while (drive)
	{
		if (!(dirp = opendir((char *)drive->content)))
			puterrdir((char *)drive->content);
		else
		{
			if (opt->i_opt > 1)
			{
				if (drive != opt->optional)
					ft_putchar('\n');
				ft_putstr((char *)drive->content);
				ft_putendl(": ");
			}
			while ((dir_entry = readdir(dirp)))
			{
				if (!opt->strict[0])
				{
					if (dir_entry->d_name[0] != '.')
						ft_putendl(dir_entry->d_name);
				}
				else
					ft_putendl(dir_entry->d_name);
			}
		}
		if (dirp)
			closedir(dirp);
		tmp = drive;
		drive = drive->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}
