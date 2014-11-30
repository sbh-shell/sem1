# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#    Updated: 2014/11/30 19:40:38 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME =		libftprintf.a

SRC =		ft_printf.c\
			ft_check.c\
			ft_init.c\
			ft_treat_cs.c\
			ft_treat_diu_v3.c\
			ft_treat_oxp.c\
			#ft_treat.c\

OBJ =		$(SRC:.c=.o)

HEADERS =	includes

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	Make -C libft
	cp libft/*.o ./
	ar rc $(NAME) $(OBJ) *.o
	ranlib $(NAME)

%.o: $(addprefix srcs/, %.c)
	$(CC) $(FLAGS) -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ) *.o libft/*.o

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all
