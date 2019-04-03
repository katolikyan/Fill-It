# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 17:12:52 by tkatolik          #+#    #+#              #
#    Updated: 2019/03/08 16:38:01 by tkatolik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		  ft_isprint.c ft_toupper.c ft_tolower.c

PART2	= ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	= ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c

OWN		= ft_strwrdc.c ft_atoi_base.c ft_lstsize.c ft_lstswapcon.c \
		  ft_treenew.c ft_lstpb.c ft_lstparams.c get_next_line.c

SRCS	=	$(PART1) $(PART2) $(BONUS) $(OWN)
OBJ		=	$(SRCS:%.c=%.o)
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -c -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)	

$(OBJ):
	$(CC) $(FLAGS) $(SRCS) 

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

