/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:41:24 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 16:48:06 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(int argc, char* argv[])
{
	int		control;

	if (argc != 2)
		exit_with_error("Wrong number of parameters");

	control = game_master(argv[1]);
	if (control == -1)
		exit_with_error("Wrong config");
	return(0);
}

/*
	game_master keeps the window open.
*/

int		game_master(char* map_path)
{
	t_game*	game;

	game = game_init(map_path);


	mlx_loop(game->screen->mlx_p);

	game_destroy(game);
	return (0);
}


/* 
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char*	dst;

	dst = data->addr +(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
} */





/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color); */

/* int		move_player(int keycode, t_game game)
{

}
int	key_hook(int keycode, t_data *img)
{
	static int	pos_x = 0;
	static int	pos_y = 0;

	printf("Hello from key_hook!%d\n", keycode);
	if (keycode == 1)
	{
		move_player(keycode, );
	}
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx_p, img->win_p);
		exit(0);
	}
	return (0);
} */




	/* //img.img = mlx_new_image(screen.mlx_p, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
		//mlx_put_image_to_window(mlx_p, win_p, img.img, argc, argc);
	img.img = mlx_xpm_file_to_image(screen.mlx_p, path, &img.i_width, &img.i_height);
	//mlx_put_image_to_window(screen.mlx_p, screen.win_p, img.img, 50, 50);
	mlx_key_hook(img.win_p, key_hook, &img);
	mlx_loop(img.mlx_p); */