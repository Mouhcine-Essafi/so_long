/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messafi <messafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:06:30 by messafi           #+#    #+#             */
/*   Updated: 2022/06/28 18:40:10 by messafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

t_save	g_a;

void	check_map(char **map)
{
	int i;
	int	j;
	int		img_w = 50;
	int		img_h = 50;

	i = 0;
	j = 0;
	while(map[i] != '\0')
	{
		while(map[i][j] != '\0')
		{
			if((map[i][j]) == '0')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/0.xpm", &img_w, &img_h), j * 50, i * 50);
			if((map[i][j]) == '1')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/1.xpm", &img_w, &img_h), j * 50, i * 50);
			if((map[i][j]) == 'C')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/C.xpm", &img_w, &img_h), j * 50, i * 50);
			if((map[i][j]) == 'E')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/E.xpm", &img_w, &img_h), j * 50, i * 50);
			if((map[i][j]) == 'P')
				mlx_put_image_to_window(g_a.mlx, g_a.mlx_win, mlx_xpm_file_to_image(g_a.mlx, "./image/P.xpm", &img_w, &img_h), j * 50, i * 50);
			j++;
			//printf("j = %d i = %d\n", j, i);
		}
		i++;
		j = 0;
	}
	
}
int	main(int ac, char **av)
{
	(void)ac;
	/*void	*mlx;
	void	*mlx_win;
	char	*str;
	int 	fd;
	char	**map;*/
	//void	*img;
	//void	*img1;
	//int		img_w = 50;
	//int		img_h= 50;
	//int i = 0;

	g_a.fd = open(av[1], O_RDWR);
	g_a.str = get_next_line(g_a.fd);
	g_a.map = ft_split(g_a.str,'\n');
	g_a.mlx = mlx_init();
	g_a.mlx_win = mlx_new_window(g_a.mlx, ft_strlen(*g_a.map) * 50, 5 * 50, "so_long");
	//img = mlx_xpm_file_to_image(mlx, "./image/P.xpm", &img_w, &img_h);
	//img1 = mlx_xpm_file_to_image(mlx, "./image/E.xpm", &img_w, &img_h);
	//mlx_put_image_to_window(mlx, mlx_win, mlx_xpm_file_to_image(mlx, "./image/P.xpm", &img_w, &img_h), 50, 0);
	//mlx_put_image_to_window(mlx, mlx_win, mlx_xpm_file_to_image(mlx, "./image/1.xpm", &img_w, &img_h), 50, 50);
	//mlx_put_image_to_window(mlx, mlx_win, mlx_xpm_file_to_image(mlx, "./image/E.xpm", &img_w, &img_h), 0, 100);
	check_map(g_a.map);
	mlx_loop(g_a.mlx);
}
