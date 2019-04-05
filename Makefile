# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 14:51:28 by amendelo          #+#    #+#              #
#    Updated: 2018/11/10 22:48:24 by amendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= eval_expr
PATH_SRC	= ./
HEADER		= ./
OPTION		= -I $(HEADER)
SRC			= eval_expr_main.c eval_expr_helpers.c atoi_move_cursor.c ft_putnbr.c
FLAG		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAG) $(OPTION) -o $(NAME) $(addprefix $(PATH_SRC), $(SRC))
clean:

fclean:	clean
		/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
