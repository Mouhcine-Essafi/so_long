/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:31:36 by messafi           #+#    #+#             */
/*   Updated: 2022/06/29 21:00:34 by messafi          ###   ########.fr       */
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

void error(int a)
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

char	check_map(char **map)
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
                return ('0');
			if ((((map[0][j]) != '1') || (map[ft_strlen2(map) - 1][j]) != '1')
				|| (((map[i][0]) != '1' )
					|| ((map[i][ft_strlen(map[i]) - 1]) != '1')))
			{
				return ('0');
			}
			j++;
		}
		i++;
		j = 0;
	}
	return ('1');
}
