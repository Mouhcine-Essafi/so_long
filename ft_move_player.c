/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:35:02 by messafi           #+#    #+#             */
/*   Updated: 2022/07/02 17:35:07 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_right_side(t_save *g, int i, int j)
{
	if (g->map[i][j + 1] == '1')
		return (0);
	else if (g->map[i][j + 1] == '0')
		return (1);
	else if (g->map[i][j + 1] == 'C')
	{
		return (2);
	}
	else if (g->map[i][j + 1] == 'E')
		return (3);
	return (0);
}

int	ft_left_side(t_save *g, int i, int j)
{
	if (g->map[i][j - 1] == '1')
		return (0);
	else if (g->map[i][j - 1] == '0')
		return (1);
	else if (g->map[i][j - 1] == 'C')
		return (2);
	else if (g->map[i][j - 1] == 'E')
		return (3);
	return (0);
}

int	ft_up(t_save *g, int i, int j)
{
	if (g->map[i - 1][j] == '1')
		return (0);
	else if (g->map[i - 1][j] == '0')
		return (1);
	else if (g->map[i - 1][j] == 'C')
		return (2);
	else if (g->map[i - 1][j] == 'E')
		return (3);
	return (0);
}

int	ft_down(t_save *g, int i, int j)
{
	if (g->map[i + 1][j] == '1')
		return (0);
	else if (g->map[i + 1][j] == '0')
		return (1);
	else if (g->map[i + 1][j] == 'C')
		return (2);
	else if (g->map[i + 1][j] == 'E')
		return (3);
	return (0);
}
