# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/26 14:26:04 by tfontain          #+#    #+#              #
#    Updated: 2017/03/27 10:48:33 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = clang
HEADER = ./fdf.h
FLAG = -Wall -Wextra -Werror -O3
OPTION = -c -I $(HEADER)
SRC = ./basic_funcs.c ./main.c ./funcs.c ./struct_operate.c ./parser.c
FK = -L/ libft/libft.a -lmlx -framework OpenGL -framework AppKit


OBJ = $(addsuffix .o,$(basename $(SRC)))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(OPTION) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(FK)
%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
