/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:21:55 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 16:51:25 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "./libft/libft.h"

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
	t_screen*	screen;
	t_data*		wall;
	t_data*		floor;
	t_data*		player;
	t_data*		finish;
	t_data*		collectible;
	int			player_x;
	int			player_y;
	int			moves;
	char**		map; 
}	t_game;

typedef struct s_map_flags
{
	int	player;
	int	exit;
	int	collectibles;
	int	enclosed;
	int	height;
	int	width;
}	t_map_flags;

// so_long.c
int			game_master(char* map_path);

// so_long_utils.c
void		exit_with_error(char* str);


// load_config.c
t_game*		game_init(char* map_path);
void		screen_init(t_game* game);


// map_utils.c

int		parse_map(t_game* game, char* map_path);
//int		map_is_valid(char** map);

// game_destroy.c
int			game_destroy(t_game* game);
void		screen_destroy(t_screen* screen);
void		data_destroy(t_data* data);
void		map_destroy(char** map);


/* 
// sprites_utils.c
int		load_sprites(t_game* game);
void	load_texture(t_game* game, t_data* data, char* path);

 */

#endif