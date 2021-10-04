/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:10:13 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/04 17:52:35 by alemarti         ###   ########.fr       */
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

	printf("\n\tmap_size:%d x %d\n", game->map_width, game->map_height);
	game->screen = (t_screen*)malloc(sizeof(t_screen));
	game->moves = 0;

			//TODO
	screen_init(game);
	if (load_sprites(game) == -1)
		exit_with_error("Fail loading sprites", game);
	if (buffer_init(game) == -1)
		exit_with_error("Fail initializing buffer image", game);
	//printf("Moves from key_hook: %d\n", game->moves);
	draw_map(game);
	
	
	return (game);
}

int	buffer_init(t_game* game)
{
	game->buffer = malloc(sizeof(t_data));
	if (game->buffer == NULL)
		return (-1);
	game->buffer->img = mlx_new_image(game->screen->mlx_p, game->screen->width, game->screen->height);
	game->buffer->addr = mlx_get_data_addr(game->buffer->img, &game->buffer->bbp, &game->buffer->line_length, &game->buffer->endian);
	return (0);
}

void	screen_init(t_game* game)
{
	int	scale;

	scale = 64;
	game->screen->width = game->map_width * scale;
	game->screen->height = game->map_height * scale;
	game->screen->mlx_p = mlx_init();
	game->screen->win_p = mlx_new_window(game->screen->mlx_p, game->screen->width, game->screen->height, "so_long");
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