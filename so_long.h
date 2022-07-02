/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:03:35 by messafi           #+#    #+#             */
/*   Updated: 2022/07/02 17:26:16 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_save
{
	void	*mlx;
	void	*mlx_win;
	char	*str;
	int		fd;
	char	**map;
	int		w;
	int		h;
	int		i;
	int		j;
}	t_save;

int		check_map(char **map);
int		ft_strlen2(char **map);
void	error(int a);
int		ft_strlen2(char **map);
int		ft_handle_key(int key, t_save *g);
void	draw_map(char **map, t_save g);
void	*read_map(char c, t_save g);
//void	move_player(char c, t_save *g);
void	ft_player_position(t_save *g, char c);
int		ft_right_side(t_save *g, int i, int j);
int		ft_left_side(t_save *g, int i, int j);
int		ft_up(t_save *g, int i, int j);
int		ft_down(t_save *g, int i, int j);

#endif
