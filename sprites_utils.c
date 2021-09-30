/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:00:58 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 16:23:04 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		load_sprites(t_game* game)
{
	load_texture(game, game->wall, "./sprites/wall.xpm");
	load_texture(game, game->player, "./sprites/player.xpm");
	load_texture(game, game->floor, "./sprites/floor.xpm");
	load_texture(game, game->collectible, "./sprites/collectible.xpm");
	load_texture(game, game->finish, "./sprites/finish.xpm");

	if (!game->floor->img || !game->wall->img || !game->player->img || !game->finish->img || !game->collectible->img)
		exit_with_error("Error loading sprites");
	return (0);
}

void	load_texture(t_game* game, t_data* data, char* path)
{
	data->img = mlx_xpm_file_to_image(game->screen->mlx_p, path, data->width, data->height);
}






