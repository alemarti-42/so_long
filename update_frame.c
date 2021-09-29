/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:34:32 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/29 14:34:36 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	move_player function updates game.player_x and game.player_y based on keystrokes.
*/

void	move_player(t_game game, char key)
{
	int	unit_move;
	int	up_key;
	int	down_key;
	int	right_key;
	int	left_key;

	up_key = ;
	down_key = ;
	right_key = ;
	left_key = ;
	unit_move = 20;

	if (key == up_key)
		game.player_y += unit_move;
	if (key == down_key)
		game.player_y -= unit_move;
	if (key == right_key)
		game.player_x += unit_move;
	if (key == left_key)
		game.player_x -= unit_move;
}