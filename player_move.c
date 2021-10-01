/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:39:39 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/01 17:46:35 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_up(t_game* game)
{
	ft_putstr_fd("UP\n", 0);
	return (move_player(game, 0, -1));
}

int move_down(t_game* game)
{
	ft_putstr_fd("DOWN\n", 0);
	return (move_player(game, 0, 1));
}

int move_left(t_game* game)
{
	ft_putstr_fd("LEFT\n", 0);
	return (move_player(game, -1, 0));
}

int move_right(t_game* game)
{
	ft_putstr_fd("RIGHT\n", 0);
	return (move_player(game, 1, 0));
}

int	move_player(t_game* game, int mov_x, int mov_y)
{
	int	new_x;
	int	new_y;

	printf("\nPlayer posistion: %d , %d\n", game->player_x, game->player_y);
	new_x = game->player_x + mov_x;
	new_y = game->player_y + mov_y;
	if (game->map[new_y][new_x] == 'E' && game->collectibles != 0)
		return (0);
	if (game->map[new_y][new_x] == 'E')
		printf("\nCongratulations!! [%d moves]\n", game->moves);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	return (1);
}
