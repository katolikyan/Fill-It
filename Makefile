# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/01 18:59:42 by tkatolik          #+#    #+#              #
#    Updated: 2019/03/08 16:36:55 by tkatolik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit

# --------------------------------------------------------------

SRC		:= main.c check_input.c solver.c build_map.c store_tetri.c read_input.c

OBJ		:= $(SRC:%.c=%.o)

CC		:= gcc

FLAGS	:= -Wall -Wextra -Werror -c -I.

# --------------------------------------------------------------

# LIB_DIR := ./libft

# --------------------------------------------------------------

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): LIB $(OBJ)
	@$(CC) $(OBJ) ./libft/libft.a -o $(NAME) 

LIB:
	@$(MAKE) -C ./libft/ 

$(OBJ):
	@$(CC) $(FLAGS) $(SRC)

clean: 
	@rm -rf *.o
	@$(MAKE) -C ./libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft/ fclean
	@echo "\nEverything is cleaned ヽ(´ー｀)"

re: fclean all
