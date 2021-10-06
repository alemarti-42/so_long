/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:41:24 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 18:52:26 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		exit_with_error("Wrong number of parameters", NULL);
	if (game_master(argv[1]) == -1)
		exit_with_error("Error on game", NULL);
	return (0);
}

int	game_master(char *map_path)
{
	t_game	*game;

	game = game_init(map_path);
	if (!game)
		return (-1);
	mlx_key_hook(game->screen->win_p, key_hook, game);
	mlx_hook(game->screen->win_p, 17, 0, game_safe_kill, game);
	mlx_loop(game->screen->mlx_p);
	game_destroy(game);
	return (0);
}

int	key_hook(int keycode, t_game *game )
{
	if (keycode == 53)
		game_safe_kill(game);
	if (game->collectibles == -1)
		return (0);
	if (keycode == 13)
		game->moves += move_up(game);
	else if (keycode == 1)
		game->moves += move_down(game);
	else if (keycode == 0)
		game->moves += move_left(game);
	else if (keycode == 2)
		game->moves += move_right(game);
	else
		return (0);
	return (0);
}
