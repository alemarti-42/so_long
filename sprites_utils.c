/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:00:58 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/04 18:39:44 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		load_sprites(t_game* game)
{
	game->wall = malloc(sizeof(t_data));
	game->floor = malloc(sizeof(t_data));
	game->player = malloc(sizeof(t_data));
	game->collectible = malloc(sizeof(t_data));
	game->finish = malloc(sizeof(t_data));
	if (!game->wall || !game->player || !game->floor|| !game->collectible || !game->finish)
		return(return_with_error("Memory fail"));
	load_texture(game, game->wall, "./sprites/wall.xpm");
	load_texture(game, game->player, "./sprites/player.xpm");
	load_texture(game, game->floor, "./sprites/floor.xpm");
	load_texture(game, game->collectible, "./sprites/collectible.xpm");
	load_texture(game, game->finish, "./sprites/finish.xpm");
	if (!game->wall->img || !game->player->img || !game->floor->img|| !game->collectible->img || !game->finish->img)
	{
	
		return (return_with_error("Textures fail"));
	}

	//if (!game->floor->img || !game->wall->img || !game->player->img || !game->finish->img || !game->collectible->img)
	//	exit_with_error("Error loading sprites", game);
	return (0);
}

void	load_texture(t_game* game, t_data* data, char* path)
{
//	path = 0;
	data->width = 0;
	data->height = 0;
	printf("\naddr1:%p\n", data->addr);
	//printf("\nPUNTEROS[%s]\nmlx: %p\ndata->img: %p\nw: %d\nh: %d\n",path, game->screen->mlx_p, data->img, data->width, data->height);
	//printf("\nPATH\npath: %s\nw: %p\nh: %p\n", path, &data->width, &data->height);

	data->img = mlx_xpm_file_to_image(game->screen->mlx_p, path, &data->width, &data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length, &data->endian);

	printf("\naddr2:%p\n", data->addr);

	printf("\nPUNTEROS[%s]\nmlx: %p\ndata->img: %p\nw: %d\nh: %d\n",path, game->screen->mlx_p, data->img, data->width, data->height);
	printf("\n##########################\n\n");
	}






