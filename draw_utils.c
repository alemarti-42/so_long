/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:39:31 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 14:45:56 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			print_window_cell(game, game->map[i][j], j, i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	print_window_cell(t_game *game, char c, int i, int j)
{
	mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, \
	 game->floor->img, 64 * i, 64 * j);
	if (c == '1')
		return (put_sprite(game, game->wall, i, j));
	if (c == '0')
		return (put_sprite(game, game->floor, i, j));
	if (c == 'C')
		return (put_sprite(game, game->collectible, i, j));
	if (c == 'P')
		return (put_sprite(game, game->player, i, j));
	if (c == 'E')
		return (put_sprite(game, game->finish, i, j));
	return (-1);
}	

int	put_sprite(t_game *game, t_data *sprite, int pos_x, int pos_y)
{
	mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, \
	 sprite->img, 64 * pos_x, 64 * pos_y);
	return (0);
}
