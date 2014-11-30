
#ifndef VOTRE_PROJET_H
# define VOTRE_PROJET_H

# include "libft.h"
# include <stdarg.h>

typedef struct		s_expr
{
	int			flag[5];
	int			length;
	int			width;
	int			precision;
}					t_expr;

int			ft_check_flag(char *format, size_t *i, t_expr *expr);
int			ft_check_width(char *format, size_t *i, t_expr *expr);
int			ft_check_precision(char *format, size_t *i, t_expr *expr);
int			ft_check_length(char *format, size_t *i, t_expr *expr);
int			ft_check_specifier(va_list *va,  char *format, size_t *i, t_expr *expr);

int			ft_treat_s(va_list *va, t_expr *expr);
int			ft_treat_p(va_list *va, t_expr *expr);
int			ft_treat_d(va_list *va, t_expr *expr);
int			ft_treat_o(va_list *va, t_expr *expr);
int			ft_treat_u(va_list *va, t_expr *expr);
int			ft_treat_x(va_list *va, t_expr *expr);
int			ft_treat_c(va_list *va, t_expr *expr);

#endif
