/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:13 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/01 17:23:49 by alemarti         ###   ########.fr       */
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
	if (game == NULL)
		perror("Memory error");
	if (parse_map(game, map_path) == -1)
	{
		ft_putendl_fd("Map error", 2);
		return (NULL);
	}

	game->screen = (t_screen*)malloc(sizeof(t_screen));
	game->moves = 0;

//	load_sprites(game);			//TODO
	screen_init(game);
	//printf("Moves from key_hook: %d\n", game->moves);
	
	
	return (game);
}

void	screen_init(t_game* game)
{
	
	game->screen->mlx_p = mlx_init();
	game->screen->win_p = mlx_new_window(game->screen->mlx_p, 1920, 
	1080, "so_long");
	//game->screen->win_p = mlx_new_window(game->screen->mlx_p, game->screen->width, game->screen->height, "so_long");
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