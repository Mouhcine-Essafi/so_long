/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/06/27 22:53:12 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	main(int ac, char **av)
{
	(void)ac;
	void	*mlx;
	void	*mlx_win;
	char	*str;
	int 	fd;
	char	**map;
	void	*img;
	void	*img1;
	int		img_width = 50;
	int		img_height= 50;

	fd = open(av[1], O_RDWR);
	str = get_next_line(fd);
	map = ft_split(str,'\n');
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./image/P.xpm", &img_width, &img_height);
	img1 = mlx_xpm_file_to_image(mlx, "./image/E.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img1, 0, 50);
	mlx_loop(mlx);
}
