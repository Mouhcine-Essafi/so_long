/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/06/26 19:55:04 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	main(int ac, char **av)
{
	(void)ac;
	/*void	*mlx;
	void	*mlx_win;*/
	char	*str;
	int 	fd;

	fd = open(av[1], O_RDWR);
	str = get_next_line(fd);
	printf("%s", get_next_line(fd));
	/*mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);*/
}
