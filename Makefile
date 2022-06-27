# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: messafi <messafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 17:49:50 by messafi           #+#    #+#              #
#    Updated: 2022/06/26 18:49:16 by messafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c get_next_line.c get_next_line_utils.c
LIBFT = libft/libft.a

CC = gcc

FLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_HEADER = /usr/locale/include


all : $(NAME) $(LIBFT)

$(NAME) : 
	make -C libft
	$(CC) -I $(MLX_HEADER) $(MLX_FLAGS) $(SRCS) -o $@

clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all