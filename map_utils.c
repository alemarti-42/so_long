/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:11 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/29 16:05:13 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		str_is_in_set(char* set, char* str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(set, str[i]))
		{
			return (-1);
		}
	}
	return (0);
}

int		check_all_elements(char** map)
{
	t_map_flags	flags;
	int			i;
	int			j;

	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				flags->player += 1;
			if (map[i][j] == 'C')
				flags->collectibles += 1;
			if (map[i][j] == 'E')
				flags->exit += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (flags->player != 1 || flags->exit != 1 || flags->collectibles < 1)
	{
		perror("Error: Wrong number of players, exits or collectibles");
		exit(MAP_ERROR);
	}
	return (0);
}

int		map_is_valid(char** map)
{

	int	line_length;
	int	line_count;

	
	line_count = 0;
	line_length = ft_strlen(map[0]);
	if (line_length < 3)
	{
		perror("Error: Map width too small");
		exit(MAP_ERROR);
	}
	while (map[line_count] != NULL)
	{
		if (ft_strlen(map[line_count]) != line_length)
		{
			perror("Error: Map not rectangular");
			exit(MAP_ERROR);
		}
		if (str_is_in_set(set, map[line_count]) == -1)
		{
			perror("Error: Wrong map characters");
			exit(MAP_ERROR);
		}
		line_count++;
	}
	if (line_count < 3)
	{
		perror("Error: Map height too small");
		exit(MAP_ERROR);
	}
	check_all_elements(map);
	return (0);
}






int		parse_map(t_game *game, char* map_path)
{
	char*	map_raw;
	char*	swap_1:
	char*	buffer;
	int		fd;

	buffer = (char *)malloc(sizeof(char) * 100);
	buffer[99] = 0;
	map_raw = NULL;
	swap_1 = NULL;
	fd = fopen(map_path, O_RDONLY);
	if (fd < 0)
	{	
		perror("Error: File access failed")
		exit(FILE_ERROR);
	}
	while(read(fd, &buffer, 99))
	{
		swap_1 = ft_strjoin(map_raw, buffer);
		free(map_raw);
		map_raw = swap_1;
	}
	free(buffer);
	game.map = ft_split(map_raw, '/n');
	free(map_raw);
	map_is_valid(game.map)
	return (0);
}
