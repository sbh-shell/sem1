/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 16:34:27 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/22 23:22:02 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include <dirent.h>

# define MAX_STRICT 4
# define MAX_OPTIONAL 50
# define MAX_CHAR 256

typedef struct		s_opt
{
	int				strict[MAX_STRICT];
	t_uint			i_str;
	t_uint			i_opt;
	t_list			*optional;
}					t_opt;

t_opt				*alloc_opt(void);
char				treat_strict_opt(t_opt *opt, int ac, char **av);
char				treat_optional_opt(t_opt *opt, char **av);
t_opt				*init_opt(int ac, char **av);

#endif
