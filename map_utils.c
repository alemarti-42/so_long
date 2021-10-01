/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:11 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/01 15:06:51 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TESTING-----------------------------------------
void print_split(char **str)
{
	int i = 0;

	while(str[i])
	{
		printf("\nLINEA:[%d]\n", i);
		ft_putstr_fd(str[i], 0);
		i++;
	}
}
//TESTING-----------------------------------------

int		parse_map(t_game* game, char* map_path)
{
	char*	map_raw;
	char*	swap;
	char*	buffer;
	int		fd;

	if (check_ber(map_path) == -1)
		exit_with_error("Not .ber file", NULL);
	map_raw = (char*)ft_calloc(1, sizeof(char));
	swap = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{	
		perror("File access failed");
		return (-1);
	}
	buffer = (char*)ft_calloc(100, sizeof(char));
	//(char *)malloc(sizeof(char) * 100);
	//buffer[99] = 0;
	//if (buffer == NULL || map_raw == NULL)
	while(read(fd, buffer, 99) > 0)
	{
		
		//ft_putstr_fd(buffer, 0);
		swap = ft_strjoin(map_raw, buffer);
		//while (1);
		free(map_raw);
		map_raw = swap;
		ft_bzero(buffer, 100);
		
	}
	free(buffer);
	close(fd);
	/* if (ft_strlen(map_raw) == 0)
	{
		free(map_raw);
		exit_with_error("Empty map", game);
	} */
	game->map = ft_split(map_raw, '\n');
	//print_split(game->map);
	free(map_raw);
	if (map_is_valid(game->map) == -1)
		return (-1);
	return (0);
}

int	check_ber(char* map_path)
{
	int	len;
	
	len = ft_strlen(map_path);
	if (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0)
	{
		return (-1);
		printf("ES BER\n");
	}
	printf("NO ES BER\n");
	return (0);
}

int		map_is_valid(char** map)
{

	int	line_length;
	int	line_count;
	int	player;
	int	exit;
	int	collectibles;
	int enclosed;
	int	i;
	int	map_height;

	
	
	if (*map == NULL)
	{
		perror("Empty map");
		return (-1);
	}
	line_length = ft_strlen(*map);
	map_height = get_map_height(map);

	player = 0;
	exit = 0;
	collectibles = 0;
	enclosed = 0;
	line_count = 0;
	i = 0;


	while (map[line_count])
	{
		while (map[line_count][i])
		{
			if ((line_count == 0 || line_count == map_height - 1 || i == 0 || i == line_length - 1) && map[line_count][i] != '1')
				return(-1);
			if (map[line_count][i] == 'P')
				player++;
			if (map[line_count][i] == 'E')
				exit++;
			if (map[line_count][i] == 'C')
				collectibles++;
			i++;
		}
		i = 0;
		line_count++;
	}
	map_height = line_count;
	printf("\nMAP_PARSE\n\tmap_h:\t%d\n\tmap_w:\t%d\n\tpla:\t%d\n\tex:\t%d\n\tcoll:\t%d\n\tlinlen:\t%d\n", map_height, line_length, player, exit, collectibles, line_length);
	return (0);



} 

int	get_map_height(char** map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		printf("\nLINEA:[%d]\t%s\n", i, map[i]);
		i++;
	}
	return (i);
}

/*







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
 */







