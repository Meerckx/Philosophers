# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meerckx <meerckx@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:46:01 by meerckx           #+#    #+#              #
#    Updated: 2022/06/07 14:41:32 by meerckx          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	philo

HEADERS		:=	philosophers.h
SRC			:=	philosophers.c philo_init.c info_init.c start_dinner.c dinner_utils.c mem_clear.c
OBJ			:=	$(SRC:%.c=%.o)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

.PHONY : all bonus clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lpthread

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all