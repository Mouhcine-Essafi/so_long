# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: messafi <messafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 17:49:50 by messafi           #+#    #+#              #
#    Updated: 2022/07/02 16:42:05 by messafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c get_next_line.c get_next_line_utils.c\
		so_long_u.c so_long_map.c ft_move_player.c\
				
LIBFT = libft.a

CC = gcc

FLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_HEADER = /usr/locale/include


all : $(LIBFT) $(NAME)
$(LIBFT) :
	make -C libft

$(NAME) : $(SRCS)
	$(CC) -I $(MLX_HEADER) $(MLX_FLAGS) $(SRCS) libft/$(LIBFT) $(FLAGS) -o $@ -fsanitize=address

clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
