/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 21:50:15 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/16 21:05:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_lstdelbuff(t_list **alst, int fd)
{
	t_list		*drive;

	drive = *alst;
	while (drive)
	{
		if (fd == ((t_buff *)drive->content)->fd)
		{
			if (drive == *alst)
				*alst = drive->next;
			ft_buffdel((t_buff **)&drive->content);
			ft_memdel((void **)&drive);
			break ;
		}
		drive = drive->next;
	}
}

static int			ft_get_next_buff(t_buff *buff, char **line)
{
	char		*find;
	size_t		i;

	i = 1;
	*line = ft_strcat(*line, buff->buff);
	while (buff->ret = read(buff->fd, buff->buff, buff->buff_size) > 0)
	{
		*line = ft_strcat(*line, buff->buff);
		*line = ft_strexp(*line, buff->buff_size * ++i);
		if (find = ft_strchr(*line, '\n'))
		{
			(*line)[find - *line] = '\0';
			buff->buff = ft_strcpy(buff->buff, find + 1);
			break ;
		}
	}
	if (!buff->ret)
		return (0);
	return (buff->ret);
}

static t_list		*ft_get_elem(int fd, t_list **alst)
{
	t_list		*drive;

	drive = *alst;
	while (drive)
	{
		if (fd == ((t_buff *)drive->content)->fd)
			return (drive);
		drive = drive->next;
	}
	if (!(drive = ft_lstnew((void *)ft_buffnew(fd, BS), sizeof(t_buff))))
		return (NULL);
	ft_lstadd(alst, drive);
	return (drive);
}

static char			*ft_is_next_line(t_buff *buff)
{
	char	*find;
	char	*line;

	line = NULL;
	if (find = ft_strchr(buff->buff, '\n'))
	{
		line = ft_strnew(buff->buff_size);
		line = ft_strcpy(line, buff->buff);
		line[find - buff->buff] = '\0';
		buff->buff = ft_strcpy(buff->buff, find + 1);
	}
	return (line);
}

int					get_next_line(int fd, char **line)
{
	static t_list		*alst;
	t_list				*elem;

	elem = ft_get_elem(fd, &alst);
	if (*line = ft_is_next_line((t_buff *)elem->content))
		return (1);
	else
	{
		*line = ft_strnew(((t_buff *)elem->content)->buff_size);
		((t_buff *)elem->content)->ret =\
				ft_get_next_buff((t_buff *)elem->content, line);
		if (!((t_buff *)elem->content)->ret)
		{
			ft_lstdelbuff(&alst, fd);
			ft_putendl("CONGRATULATION!");
			return (0);
		}
		return (((t_buff *)elem->content)->ret);
	}
}
