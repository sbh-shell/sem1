/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:45:31 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/22 21:41:58 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTERR_H
# define PUTERR_H

# include "ls.h"

# define TITLE "ft_ls: "
# define ILLEGAL_OPT "illegal option -- "
# define NO_DIR "No such file or directory"
# define USAGE "usage: ft_ls [-alrR] [file ...]"

void				puterropt(char *bad_opt);
void				puterrdir(char *bad_dir);

#endif
