/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:13 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 16:50:12 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



/*
	game_init iniitializes the structure with the given map, sprites and so.
*/

t_game*		game_init(char* map_path)
{
	t_game*	game;

	game = (t_game*)malloc(sizeof(t_game));
	if (game == NULL || parse_map(game, map_path) == -1 )
		exit_with_error("game_init error");
	game->screen = (t_screen*)malloc(sizeof(t_screen));

//	load_sprites(game);			//TODO
	screen_init(game);

	
	
	return (game);
}

void	screen_init(t_game* game)
{
	game->screen->mlx_p = mlx_init();
	game->screen->win_p = mlx_new_window(game->screen->mlx_p, game->screen->height, game->screen->width, "so_long");
	/* if (game->screen->win_p == NULL || game->screen->mlx_p = NULL)
		exit_with_error("Screen handler fail"); */
}


/* 

//	get_player_position stores player position into the game.player_x and game.player_y sets old player position to floor.

int	get_player_position(t_game* game)
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

 */