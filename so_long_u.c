/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:31:36 by messafi           #+#    #+#             */
/*   Updated: 2022/07/02 17:28:41 by messafi          ###   ########.fr       */
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
		write(2, "undifined argumets\n", 19);
		exit(0);
	}
	if (a == 1)
	{
		write(2, "invalid map\n", 12);
		exit(0);
	}
}

int	ft_handle_key(int key, t_save *g)
{
	char	c;

	c = 0;
	if (key == 123 || key == 0)
		c = 'A';
	else if (key == 124 || key == 2)
		c = 'D';
	else if (key == 125 || key == 1)
		c = 'S';
	else if (key == 126 || key == 13)
		c = 'W';
	else if (key == 53)
		exit(1);
	ft_player_position(g, c);
	return (0);
}

void	ft_player_position(t_save *g, char c)
{
	int	i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = 0;
	while (g->map[i] != '\0')
	{
		while (g->map[i][j] != '\0')
		{
			if (g->map[i][j] == 'P')
			{
				if (c == 'D')
					s = ft_right_side(g, i, j);
				else if (c == 'A')
					s = ft_left_side(g, i, j);
				else if (c == 'S')
					s = ft_down(g, i, j);
				else if (c == 'W')
					s = ft_up(g, i, j);
				printf("%d\n", s);
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

