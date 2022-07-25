# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: messafi <messafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 17:49:50 by messafi           #+#    #+#              #
#    Updated: 2022/07/25 20:20:32 by messafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = ./bonus/so_long

SRCS = so_long.c get_next_line.c get_next_line_utils.c\
		so_long_u.c so_long_map.c ft_move_player.c\
		ft_printf.c ft_move_enemy.c\

BONUS_SRCS = ./bonus/so_long_bonus.c ./bonus/so_long_map_bonus.c\
		./bonus/so_long_u_bonus.c ./bonus/ft_move_enemy.c\
		./bonus/ft_move_player.c ./bonus/ft_printf.c ./bonus/get_next_line.c\
		./bonus/get_next_line.c\
				
LIBFT = libft.a

CC = gcc

FLAGS = -Werror -Wextra -Wall

MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_HEADER = /usr/locale/include


all : $(LIBFT) $(NAME)
$(LIBFT) :
	make -C libft

$(NAME) : $(SRCS)
	$(CC) -I $(MLX_HEADER) $(MLX_FLAGS) $(SRCS) libft/$(LIBFT) $(FLAGS) -o $@

bonus : $(NAME_BONUS)
	$(CC) -I $(MLX_HEADER) $(MLX_FLAGS) $(BONUS_SRCS) libft/$(LIBFT) $(FLAGS) -o $(NAME_BONUS)

clean :
	make clean -C libft

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all
