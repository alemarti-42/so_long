/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:41:24 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/04 16:12:44 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(int argc, char* argv[])
{
	int		control;

	if (argc != 2)
		exit_with_error("Wrong number of parameters", NULL);

	control = game_master(argv[1]);
	if (control == -1)
		exit_with_error("Wrong config", NULL);
	return(0);
}

/*
	game_master keeps the window open.
*/

int		game_master(char* map_path)
{
	t_game*	game;
	//int		moves;

	game = game_init(map_path);
	if (!game)
		return (-1);
	mlx_key_hook(game->screen->win_p, key_hook, game);
	mlx_hook(game->screen->win_p, 17, 0, game_destroy, game);
	mlx_loop(game->screen->mlx_p);
	game_destroy(game);
	return (0);
}

int	key_hook(int keycode, t_game* game)
{
	//printf("Moves from key_hook1: %d\n", game->moves);

	if (keycode == 53)
	{
		game_destroy(game);
		exit(0);
	}
	else if (keycode == 13)		
		game->moves += move_up(game);
	else if (keycode == 1)		
		game->moves += move_down(game);
	else if (keycode == 0)		
		game->moves += move_left(game);
	else if (keycode == 2)		
		game->moves += move_right(game);
 	 else
		return (0);  
//	game->moves--;
	
	print_split(game->map);
	ft_putnbr_fd(game->moves, 0);
	printf ("\n%d\tCollectibles left\n%d\tMoves\n", game->collectibles, game->moves);
//	draw_map(game);
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