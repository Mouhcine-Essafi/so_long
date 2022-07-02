/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:39:43 by messafi           #+#    #+#             */
/*   Updated: 2022/07/02 17:09:29 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char **map, t_save g)
{
	int		i;
	int		j;
	void	*s;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		while (map[i][j] != '\0')
		{
			s = read_map(map[i][j], g);
			mlx_put_image_to_window(g.mlx, g.mlx_win, s, j * 50, i * 50);
			j++;
		}
		i++;
		j = 0;
	}
}

void	*read_map(char c, t_save g)
{
	void	*s;

	if (c == '0')
		s = mlx_xpm_file_to_image(g.mlx, "images/0.xpm", &g.h, &g.w);
	if (c == '1')
		s = mlx_xpm_file_to_image(g.mlx, "images/1.xpm", &g.h, &g.w);
	if (c == 'C')
		s = mlx_xpm_file_to_image(g.mlx, "images/C.xpm", &g.h, &g.w);
	if (c == 'E')
		s = mlx_xpm_file_to_image(g.mlx, "images/E.xpm", &g.h, &g.w);
	if (c == 'P')
		s = mlx_xpm_file_to_image(g.mlx, "images/P.xpm", &g.h, &g.w);
	return (s);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		while ((map[i][j]) != '\0')
		{
			if (!(ft_strchr("01CEP", map[i][j])))
				return (0);
			if ((((map[0][j]) != '1') || (map[ft_strlen2(map) - 1][j]) != '1')
				|| (((map[i][0]) != '1' )
					|| ((map[i][ft_strlen(map[i]) - 1]) != '1')))
			{
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
