/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:00:58 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 18:56:48 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_sprites(t_game *game)
{
	game->wall = malloc(sizeof(t_data));
	game->floor = malloc(sizeof(t_data));
	game->player = malloc(sizeof(t_data));
	game->collectible = malloc(sizeof(t_data));
	game->finish = malloc(sizeof(t_data));
	if (!game->wall || !game->player || !game->floor || \
	 !game->collectible || !game->finish)
		return (return_with_error("Memory failure"));
	load_texture(game, game->wall, "./sprites/wall.xpm");
	load_texture(game, game->player, "./sprites/player.xpm");
	load_texture(game, game->floor, "./sprites/floor.xpm");
	load_texture(game, game->collectible, "./sprites/collectible.xpm");
	load_texture(game, game->finish, "./sprites/finish.xpm");
	if (!game->wall->img || !game->player->img || !game->floor->img || \
	 !game->collectible->img || !game->finish->img)
		return (return_with_error("Failure loading textures"));
	return (0);
}

void	load_texture(t_game *game, t_data *data, char *path)
{
	data->width = 0;
	data->height = 0;
	data->img = mlx_xpm_file_to_image(game->screen->mlx_p, path, \
	 &data->width, &data->height);
	if (data->img == NULL)
		exit_with_error("Failure loading sprites", NULL);
	if (data->height != 64 || data->width != 64)
		exit_with_error("Wrong sprites size. Only 64x64", NULL);
}
