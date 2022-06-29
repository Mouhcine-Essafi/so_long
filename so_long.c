/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/06/29 19:49:26 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char **map, t_save g_a)
{
	int	i;
	int	j;
	int	img_w;
	int	img_h;

	i = 0;
	j = 0;
	img_h = 50;
	img_w = 50;
	while (map[i] != '\0')
	{
		while (map[i][j] != '\0')
		{
			if ((map[i][j]) == '0')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/0.xpm", &img_w, &img_h), j * 50, i * 50);
			if ((map[i][j]) == '1')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/1.xpm", &img_w, &img_h), j * 50, i * 50);
			if ((map[i][j]) == 'C')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/C.xpm", &img_w, &img_h), j * 50, i * 50);
			if ((map[i][j]) == 'E')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/E.xpm", &img_w, &img_h), j * 50, i * 50);
			if ((map[i][j]) == 'P')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/P.xpm", &img_w, &img_h), j * 50, i * 50);
			j++;
		}
		i++;
		j = 0;
	}
}

int	main(int ac, char **av)
{
	t_save g_a;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ac != 2)
		error(0);
	g_a.fd = open(av[1], O_RDWR);
	g_a.str = get_next_line(g_a.fd);
	g_a.map = ft_split(g_a.str, '\n');
	if ((check_map(g_a.map)) == '1')
	{
		g_a.mlx = mlx_init();
		g_a.mlx_win = mlx_new_window(g_a.mlx, ft_strlen(*g_a.map) * 50,
			(ft_strlen2(g_a.map)) * 50, "so_long");
		draw_map(g_a.map, g_a);
		mlx_loop(g_a.mlx);
	}
	else
		error(1);
}