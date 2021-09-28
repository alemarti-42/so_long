/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:13 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/28 17:10:14 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

/*
	game_init initializes the connection, window, sprites and structures needed for the program.
*/

t_game	game_init(int res_x, int res_y, char* map_raw)
{
	t_game game;

	game.screen->height = res_x;
	game.screen->width = res_y;

	game.screen->mlx_p = mlx_init();
	game.screen->win_p = mlx_new_window(game.screen->mlx_p, game.screen->height, game.screen->width, "so_long");
	
	game.floor->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/floor.xpm", &game.floor->width, &game.floor->height);
	game.wall->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/wall.xpm", &game.wall->width, &game.wall->height);
	game.player->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/player.xpm", &game.player->width, &game.player->height);
	game.finish->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/finish.xpm", &game.finish->width, &game.finish->height);
	game.collectible->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/finish.xpm", &game.collectible->width, &game.collectible->height);
	
	game.map = ft_split(map_raw, '/n');
	get_player_position(t_game game);
	
	return (game);
}

void	set_collectibles(t_game game)
{

}
/*
	get_player_position stores player position into the game.player_x and game.player_y sets old player position to floor.
*/
void	get_player_position(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game.map[i][j] != 0)
	{
		while (game.map[i][j] != 0)
		{
			if (game.map[i][j] == 'P')
			{
				game.player_x = i;
				game.player_y = j;
				game.map[i][j] == '0'
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
	move_player function updates game.player_x and game.player_y based on keystrokes.
*/

void	move_player(t_game game, char key)
{
	int	unit_move;
	int	up_key;
	int	down_key;
	int	right_key;
	int	left_key;

	up_key = ;
	down_key = ;
	right_key = ;
	left_key = ;
	unit_move = 20;

	if (key == up_key)
		game.player_y += unit_move;
	if (key == down_key)
		game.player_y -= unit_move;
	if (key == right_key)
		game.player_x += unit_move;
	if (key == left_key)
		game.player_x -= unit_move;
}