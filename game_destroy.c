/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:44:57 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/05 14:40:30 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_destroy(t_game *game)
{
	if (game == NULL)
		return (0);
	//printf("\n[DESTROY]\ngame:%p\nscr:%p\nwin:%p\nmlx:%p\n", game, game->screen, game->screen->mlx_p, game->screen->win_p);
	screen_destroy(game->screen);
	//data_destroy(game->wall);
	//data_destroy(game->floor);
	//data_destroy(game->player);
	//data_destroy(game->finish);
	//data_destroy(game->collectible);
	//map_destroy(game->map);
	free(game);
	exit (0);
}

void	screen_destroy(t_screen *screen)
{
	mlx_destroy_window(screen->mlx_p, screen->win_p);
}

void	data_destroy(t_data *data)
{
	data = NULL;
}

void	map_destroy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
