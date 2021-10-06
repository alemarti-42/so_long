/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:44:57 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 14:29:54 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_destroy(t_game *game)
{
	if (game == NULL)
		return (0);
	data_destroy(game, game->player);
	data_destroy(game, game->floor);
	data_destroy(game, game->collectible);
	data_destroy(game, game->finish);
	data_destroy(game, game->wall);
	screen_destroy(game->screen);
	map_destroy(game->map);
	free(game);
	return (0);
}

void	screen_destroy(t_screen *screen)
{
	mlx_destroy_window(screen->mlx_p, screen->win_p);
	free(screen);
}

void	data_destroy(t_game *game, t_data *data)
{
	mlx_destroy_image(game->screen->mlx_p, data->img);
	free(data);
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
