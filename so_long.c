/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/06/30 20:53:46 by messafi          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_save	g;

	g.h = 50;
	g.w = 50;
	if (ac != 2)
		error(0);
	g.fd = open(av[1], O_RDWR);
	if (g.fd < 0)
		return (0);
	g.str = get_next_line(g.fd);
	g.map = ft_split(g.str, '\n');
	if (check_map(g.map))
	{
		g.mlx = mlx_init();
		g.mlx_win = mlx_new_window(g.mlx, ft_strlen(*g.map) * 50,
				(ft_strlen2(g.map)) * 50, "so_long");
		draw_map(g.map, g);
		mlx_key_hook(g.mlx_win, ft_handle_key, &g);
		mlx_loop(g.mlx);
	}
	else
		error(1);
}
