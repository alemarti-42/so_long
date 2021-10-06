/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:11 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 18:21:37 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(t_game *game, char *map_path)
{
	char	*map_raw;

	if (check_ber(map_path) == -1)
		return (return_with_error("Wrong file extension .ber"));
	map_raw = read_raw(map_path);
	if (map_raw == NULL)
		return (return_with_error("Map not found"));
	if (ft_strlen(map_raw) == 0)
	{
		free(map_raw);
		return (return_with_error("Empty map"));
	}
	game->map = ft_split(map_raw, '\n');
	free(map_raw);
	if (map_is_valid(game) == -1)
		return (-1);
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
	map_raw = NULL;
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

static void	flags_init(t_map_flags *flags, int *lines, int *i)
{
	flags->player = 0;
	flags->exit = 0;
	flags->collectibles = 0;
	*lines = 0;
	*i = 0;
}

int	map_is_valid(t_game *game)
{
	t_map_flags	flags;
	int			lines;
	int			i;

	flags_init(&flags, &lines, &i);
	if (game->map == NULL)
		return (return_with_error("Empty file"));
	if (check_map_size(game) == -1)
		return (-1);
	while (game->map[lines])
	{
		if (ft_strlen(game->map[lines]) != (size_t)game->map_width)
			return (return_with_error("Not rectangular map"));
		while (game->map[lines][i])
			if (update_flags(game, &flags, lines, i++) == -1)
				return (-1);
		i = 0;
		lines++;
	}
	game->collectibles = flags.collectibles;
	game->map_height = lines;
	if (check_elements(flags) == -1)
		return (-1);
	return (0);
}
