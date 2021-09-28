/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:21:55 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/27 17:21:57 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

/*
	t_data stores an image with its properties.
*/

typedef struct s_data
{
	void*	img;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

/*
	t_screen stores the screen connection, the reference to the window and the size of the window.
*/

typedef struct s_screen
{
	void*	mlx_p;
	void*	win_p;
	int		width;
	int		height;
}	t_screen;

/*
	t_game encapsulates the rest of structures as the player position.
*/

typedef struct s_game
{
	t_screen	screen;
	t_data		wall;
	t_data		floor;
	t_data		player;
	t_data		finish;
	t_data		collectible;
	int			player_x;
	int			player_y;
	char**		map; 
}	t_game;

#endif