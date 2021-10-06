/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:11 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 15:31:23 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TESTING-----------------------------------------
/* void print_split(char **str)
{
	int i = 0;

	while(str[i])
	{
		//printf("\nLINEA:[%d]\n", i);
		printf("\n%s\n", str[i]);
		//ft_putendl_fd(str[i], 0);
		i++;
	}
} */
//TESTING-----------------------------------------
int	parse_map(t_game *game, char *map_path)
{
	char	*map_raw;

	if (check_ber(map_path) == -1)
		return (return_with_error("Wrong file extension .ber"));
	map_raw = read_raw(map_path);
	if (map_raw == NULL)
		return (return_with_error("Failure parsing map"));
	if (ft_strlen(map_raw) == 0)
	{
		free(map_raw);
		return (return_with_error("Empty map"));
	}
	game->map = ft_split(map_raw, '\n');
	free(map_raw);
	if (map_is_valid(game) == -1)
		return (return_with_error("Invalid map"));
	printf("\nWidth:\t%d\nHeight:\t%d\n", game->map_width, game->map_height);
	return (0);
}

char	*read_raw(char *map_path)
{
	char	*map_raw;
	char	*buffer;
	char	*swap;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_raw = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(100, sizeof(char));
	swap = NULL;
	while (read(fd, buffer, 99) > 0)
	{
		swap = ft_strjoin(map_raw, buffer);
		free(map_raw);
		map_raw = swap;
		ft_bzero(buffer, 100);
	}
	free(buffer);
	close(fd);
	return (map_raw);
}

int	check_ber(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0)
		return (-1);
	return (0);
}

int	map_is_valid(t_game *game)
{
	t_map_flags	flags;
	int			lines;
	int			i;

	flags.player = 0;
	flags.exit = 0;
	flags.enclosed = 0;
	lines = 0;
	i = 0;
	if (game->map == NULL)
		return (return_with_error("Empty file"));
	if (check_map_size(game) == -1)
		return (return_with_error("Wrong map size"));
	game->collectibles = 0;
	while (game->map[lines])
	{
		if (ft_strlen(game->map[lines]) != (size_t)game->map_width)
			return (return_with_error("Not rectangular map"));
		while (game->map[lines][i])
		{
			if ((lines == 0 || i == game->map_width - 1 || lines == \
			 game->map_height - 1 || i == 0 ) && game->map[lines][i] != '1')
				return (return_with_error("Not enclosed map"));
			else if (game->map[lines][i] == 'P')
			{
				game->player_x = i;
				game->player_y = lines;
				flags.player++;
			}
			else if (game->map[lines][i] == 'E')
				flags.exit++;
			else if (game->map[lines][i] == 'C')
				game->collectibles++;
			else if (game->map[lines][i] != '0' && \
			 game->map[lines][i] != '1')
				return (return_with_error("Not allowed characters"));
			i++;
		}
		i = 0;
		lines++;
	}
	game->map_height = lines;
	if (flags.player != 1 || flags.exit != 1 || game->collectibles < 1)
		return (return_with_error("Wrong number of some elements"));
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

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}
