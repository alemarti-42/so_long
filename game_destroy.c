/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:44:57 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 16:52:21 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	game_destroy(t_game* game)
{
	screen_destroy(game->screen);
	data_destroy(game->wall);
	data_destroy(game->floor);
	data_destroy(game->player);
	data_destroy(game->finish);
	data_destroy(game->collectible);
	map_destroy(game->map);
	free(game);
	return (0);
}

void		screen_destroy(t_screen* screen)
{
	mlx_destroy_window(screen->mlx_p, screen->win_p);
	free(screen);
}

void		data_destroy(t_data* data)
{
	free(data);
}

void		map_destroy(char** map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}