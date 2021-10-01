/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:00:58 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/01 19:18:29 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		load_sprites(t_game* game)
{
	game->wall = malloc(sizeof(t_data));
	load_texture(game, game->wall, "./sprites/wall.xpm");
	load_texture(game, game->player, "./sprites/player.xpm");
	load_texture(game, game->floor, "./sprites/floor.xpm");
	load_texture(game, game->collectible, "./sprites/collectible.xpm");
	load_texture(game, game->finish, "./sprites/finish.xpm");

	if (!game->floor->img || !game->wall->img || !game->player->img || !game->finish->img || !game->collectible->img)
		exit_with_error("Error loading sprites", game);
	return (0);
}

void	load_texture(t_game* game, t_data* data, char* path)
{
	int	size;

	size = 64;	
	printf("\nPUNTEROS1\n%p\n%p\n%p\n", game->screen->mlx_p, &data->width, &data->height);
	data->img = mlx_xpm_file_to_image(game->screen->mlx_p, path, &size, &size);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length, &data->endian);

	printf("\nPUNTEROS2\n%p\n%p\n%p\n", game->screen->mlx_p, &data->width, &data->height);
}






