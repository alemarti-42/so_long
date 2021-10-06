/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:49:47 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 18:16:09 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_flags(t_game *game, t_map_flags *flags, int line, int col)
{
	if ((line == 0 || col == game->map_width - 1 || line == \
	 game->map_height - 1 || col == 0 ) && game->map[line][col] != '1')
		return (return_with_error("Not enclosed map"));
	if (game->map[line][col] == 'P')
	{
		game->player_x = col;
		game->player_y = line;
		flags->player++;
	}
	else if (game->map[line][col] == 'E')
		flags->exit++;
	else if (game->map[line][col] == 'C')
		flags->collectibles++;
	else if (game->map[line][col] != '0' && \
		game->map[line][col] != '1')
		return (return_with_error("Invalid character on map"));
	return (0);
}

int	check_map_size(t_game *game)
{
	game->map_width = ft_strlen(*game->map);
	game->map_height = get_map_height(game->map);
	if (game->map_height > 21 )
		return (return_with_error("Map too tall. Max 21"));
	if (game->map_width > 40)
		return (return_with_error("Map too wide. Max 40"));
	return (0);
}

int	check_elements(t_map_flags flags)
{
	if (flags.player == 0)
		return (return_with_error("No starting position on map"));
	if (flags.player > 1)
		return (return_with_error("More than one starting position on map"));
	if (flags.exit == 0)
		return (return_with_error("No exit on map"));
	if (flags.exit > 1)
		return (return_with_error("More than one exit on map"));
	if (flags.collectibles < 1)
		return (return_with_error("No collectibles on map"));
	return (0);
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
