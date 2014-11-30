/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 19:21:42 by sbenning          #+#    #+#             */
/*   Updated: 2014/11/30 19:32:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

# define SHORT 1
# define SCHAR 2
# define LINT 3
# define LLINT 4
# define IMAX 5
# define SSIZE 6

# define SHARP 0
# define PLUS 1
# define MINUS 2
# define SPACE 3
# define ZERO 4

# define PRECISION 0
# define WIDTH 1

# define ABS(x) ((x < 0) ? (x = -x) : (x))

typedef long long int t_llint;
typedef struct		s_expr
{
	int				flag[5];
	int				length;
	size_t			width;
	size_t			precision;
}					t_expr;

void				ft_init_expr(t_expr *expr);

int					ft_check_flag(char *format, size_t *i, t_expr *expr);
int					ft_check_width(char *format, size_t *i, t_expr *expr);
int					ft_check_precision(char *format, size_t *i, t_expr *expr);
int					ft_check_length(char *format, size_t *i, t_expr *expr);
int					ft_apply_to_specifier(va_list *va,  char *format, size_t *i, t_expr *expr);

int					ft_treat_s(va_list *va, t_expr *expr);
int					ft_treat_p(va_list *va, t_expr *expr);
size_t				ft_treat_d(va_list *va, t_expr *expr);
int					ft_treat_o(va_list *va, t_expr *expr);
int					ft_treat_u(va_list *va, t_expr *expr);
int					ft_treat_x(va_list *va, t_expr *expr);
int					ft_treat_c(va_list *va, t_expr *expr);

t_llint				ft_length_d(va_list *va, t_expr *expr);
size_t				ft_nbr_digit(t_llint nbr);
char				*ft_fill(int c, size_t len);
void				ft_aff_d(t_llint arg, t_expr *expr, char **builtin, char c);
void				ft_build_d(t_llint arg, t_expr *expr, size_t nb_d);

#endif
