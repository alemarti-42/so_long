/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:41:24 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/27 15:43:06 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	main(int argc, char* argv[])
{
	t_data	img;
	void*	mlx_p;
	void*	win_p;
	int i_width;
	int i_height;
	char *path;

	path = "./sprites/barrel.xpm";
	argc = 0;
	argv = 0;

	mlx_p = mlx_init();
	win_p = mlx_new_window(mlx_p, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx_p, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (argc++ < 1000)
	my_mlx_pixel_put(&img, argc, argc,  0x00FF0000);
	mlx_put_image_to_window(mlx_p, win_p, img.img, 0, 0);
	img.img = mlx_xpm_file_to_image(mlx_p, path, &i_width, &i_height);
	mlx_put_image_to_window(mlx_p, win_p, img.img, 50, 50);
	while (argc++ < 1000)
	my_mlx_pixel_put(img.img, argc, argc,  0x00FF0000);
	mlx_put_image_to_window(mlx_p, win_p, img.img, 0, 0);
	mlx_loop(mlx_p);

	return(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char*	dst;

	dst = data->addr +(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}