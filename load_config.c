/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:13 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/28 17:10:14 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int		load_texture(t_data texture, char* path)
{
	texture->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/floor.xpm", &game.floor->width, &game.floor->height);
}

int		load_sprites(t_game game)
{
	game.floor->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/floor.xpm", &game.floor->width, &game.floor->height);
	game.wall->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/wall.xpm", &game.wall->width, &game.wall->height);
	game.player->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/player.xpm", &game.player->width, &game.player->height);
	game.finish->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/finish.xpm", &game.finish->width, &game.finish->height);
	game.collectible->img = mlx_xpm_file_to_image(screen.mlx_p, "./sprites/collectible.xpm", &game.collectible->width, &game.collectible->height);
	if (!game.floor->img || !game.wall->img || !game.player->img || !game.finish->img || !game.collectible->img)
	{
		perror("Error: ");
		return (-1);
	}
	return (0);
}



/*
	game_init initializes the connection, window, sprites and structures needed for the program.
*/

t_game	*game_init(char* map_path)
{
	t_game *game;

	game = (t_game)malloc(sizeof(t_game));
	if (parse_map(game, map_path) == -1 || get_player_position(t_game game) == -1)
	{
		perror("Game_init Error");
	}

	load_sprites();				//TODO
	
	game.screen->mlx_p = mlx_init();
	game.screen->win_p = mlx_new_window(game.screen->mlx_p, game.screen->height, game.screen->width, "so_long");

	return (game);
}

/*
	get_player_position stores player position into the game.player_x and game.player_y sets old player position to floor.
*/
int	get_player_position(t_game game)
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
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	perror("Player missing Error")
	return (-1);
}