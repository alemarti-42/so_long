/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:39:31 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/04 18:05:29 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_map(t_game* game)
{
	//print_buffer_cell(game->buffer, game->wall->img, 4, 4);
	/* mlx_put_image_to_window (game->screen->mlx_p, game->buffer->img, game->wall->addr, 0, 0 );
	mlx_put_image_to_window (game->screen->mlx_p, game->buffer->img, game->wall->addr, 32, 32 );
	mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, game->buffer->img, 32, 32 ); */
	//offset = (y * line_bytes) + (x * 4);

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
	//mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, game->buffer->img, 0, 0 );
	return (0);
}

int	print_window_cell(t_game* game, char c, int i, int j)
{
	mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, game->floor->img, 64 * i, 64 * j);
	if (c == '1')
		return (put_sprite(game, game->wall, i , j));
	if (c == '0')
		return (put_sprite(game, game->floor, i , j));
	if (c == 'C')
		return (put_sprite(game, game->collectible, i , j));
	if (c == 'P')
		return (put_sprite(game, game->player, i , j));
	if (c == 'E')
		return (put_sprite(game, game->finish, i , j));
	return (-1);
}	

int	put_sprite(t_game* game, t_data* sprite, int pos_x , int pos_y)
{

	mlx_put_image_to_window (game->screen->mlx_p, game->screen->win_p, sprite->img, 64 * pos_x, 64 * pos_y);
	return (0);
}


/* int	print_buffer_cell(t_data* buffer, t_data* sprite, int pos_x, int pos_y)
{
	int	count_x;
	int	count_y;

	count_x = 0;
	count_y = 0;
	while (count_y < sprite->height && count_y + pos_y < buffer->height)
	{
		if (pos_x + sprite->line_length < buffer->width)
			ft_memcpy(&buffer->addr[(count_y * buffer->line_length) + pos_x], &sprite->addr[(count_y * sprite->line_length)], sprite->line_length);
		count_x = 0;
		count_y++;
	}
	printf("\nWOLAAAA|%s|\n", buffer->addr);
	return (0);
} */

/* int	print_buffer_cell(t_data* buffer, t_data* sprite, int pos_x, int pos_y)
{
	int	count_x;
	int	count_y;
	int	buffer_offset;
	int	sprite_offset;

	count_x = 0;
	count_y = 0;
	buffer_offset = (pos_y * buffer->line_length) + (pos_x * 4);
	sprite_offset = (pos_y * sprite->line_length) + (pos_x * 4);
	while (count_y < game->screen->height)
	{
		while (count_x < sprite->line_length)
		{
			buffer->addr[buffer_offset] = sprite->addr[sprite_offset];
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
	buffer->addr[offset] = 
	while (count_x < buffer->)
} */