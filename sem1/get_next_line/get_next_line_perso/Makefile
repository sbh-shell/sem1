# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/08 20:00:17 by sbenning          #+#    #+#              #
#    Updated: 2014/11/16 13:38:31 by sbenning         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME =		get_next_line

SRC =		get_next_line.c\

OBJ =		$(SRC:.c=.o)

HEADERS =	includes

LIB =		libft.a

CC =		gcc

FLAGS =		-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $< -I $(HEADERS) $(LIB) main.c

%.o: $(addprefix srcs/, %.c)
	$(CC) $(FLAGS) -c $< -I $(HEADERS)

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

