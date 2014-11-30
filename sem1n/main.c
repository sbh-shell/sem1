
#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
/*
typedef struct			s_arg
{
	int		*start;
	char	*format;
}						t_arg;

static void	my_free(char **tab, t_arg *arg)
{
	t_uint		i;

	i = MAX_UINT;
	while (tab[++i])
		ft_memdel((void **)&(tab[i]));
	ft_memdel((void **)&tab);
	ft_memdel((void **)&(arg->start));
	ft_memdel((void **)&(arg->format));
	ft_memdel((void **)&arg);
}

t_arg	*ft_format(char *format, int skip, int ca)
{
	t_arg		*arg;
	t_uint		i;
	t_uint		j;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	if (!(arg->start = (int *)malloc(sizeof(int) * ca)))
		return (NULL);
	if (!(arg->format = (char *)malloc(sizeof(char) * ca + 1)))
		return (NULL);
	arg->format[ca] = '\0';
	i = MAX_UINT;
	j = 0;
	while (format[++i])
	{
		if (format[i] == skip)
		{
			arg->start[j] = i;
			arg->format[j] = format[i + 1];
			++j;
		}
	}
	return (arg);
}

int		ft_strrrchr(char *format, int skip)
{
	t_uint		i;
	int			oc;

	oc = 0;
	i = MAX_UINT;
	while (format[++i])
		if (format[i] == skip)
			++oc;
	return (oc);
}


int		ft_printf(char *format, ...)
{
	va_list			va;
	int				ca;
	t_arg			*arg;
	char			*arg_char;
	char			**tab;
	size_t			i = -1;

	ca = ft_strrrchr(format, '%');
	if (!(tab = ft_my_strsplit(format, '%', 1)))
		return (-1);
	if (!(arg = ft_format(format, '%', ca)))
		return (-1);
	va_start(va, format);
	i = 0;
	while (ca--)
	{
		ft_putstr(tab[i]);
		if (arg->format[i] == 'd' || arg->format[i] == 'c')
			arg_char = ft_itoa(va_arg(va, int));
		if (arg->format[i] == 's')
			arg_char = va_arg(va, char *);
		ft_putstr(arg_char);
		i++;
	}
	ft_putstr(tab[i]);
	my_free(tab, arg);
	return (0);
}
*/
int		ft_is_specifier(char c)
{
	if (c == 'd' || c == 's' || c == 'p' || c == 'u' || c == 'i' || c == 'c' || c == 'x' || c == 'o')
		return (1);
	return (0);
}

static void		ft_create_elem(t_list **alst, char *str, t_uint *start, size_t *len)
{
	ft_lstadd_back(alst, ft_lstnew((void *)ft_strsub(str, *start, *len), sizeof(char) * (*len + 1)));
	*start = 0;
	*len = 0;
}

static int		ft_parse_str(char *str, t_list **alst)
{
	size_t		i;
	size_t		len;
	t_uint		start;

	i = 0;
	len = 0;
	while (str[i])
	{
		ft_maj_lst(alst, str, &i);
		if (str[i] != '%')
		{
			start = i;
			while (str[i] && str[i] != '%')
			{
				++i;
				++len;
			}
			ft_create_elem(alst, str, &start, &len);
		}
		if (str[i] == '%')
		{
			start = i;
			while (str[i] && !ft_is_specifier(str[i]))
			{
				++len; i++;
			}
			ft_create_elem(alst, str, &start, &len);
		}
		++i;
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (!ac || !av)
		return (-1);
	t_list		*alst;
	int			ret;
	t_list		*drive;

	char		str[51];
	ft_strcpy(str, "ABC%#ldEFG%sHIJ%#32ldK");
	ret = ft_parse_str(str, &alst);
	drive = alst;
	while (drive)
	{
		ft_putendl((char *)drive->content);
		drive = drive->next;
	}
	printf("%#.23%");
	return (0);
}
