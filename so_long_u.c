/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:31:36 by messafi           #+#    #+#             */
/*   Updated: 2022/06/30 20:53:58 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen2(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	error(int a)
{
	if (a == 0)
	{
		write(1, "undifined argumets\n", 19);
		exit(0);
	}
	if (a == 1)
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
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

int	ft_handle_key(int key, t_save g)
{
	(void)g;
	printf("%d\n", key);
	return (key);
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
