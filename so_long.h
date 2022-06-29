/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:03:35 by messafi           #+#    #+#             */
/*   Updated: 2022/06/29 19:39:06 by messafi          ###   ########.fr       */
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
	int 	fd;
	char	**map;
}   t_save;

char	check_map(char **map);
int		ft_strlen2(char **map);
void	error(int a);
int		ft_strlen2(char **map);

#endif
