/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:05:11 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/01 18:25:44 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TESTING-----------------------------------------
void print_split(char **str)
{
	int i = 0;

	while(str[i])
	{
		//printf("\nLINEA:[%d]\n", i);
		ft_putendl_fd(str[i], 0);
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
		return(return_with_error("Wrong file extension .ber"));
	map_raw = (char*)ft_calloc(1, sizeof(char));
	swap = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return(return_with_error("File access failed"));
	buffer = (char*)ft_calloc(100, sizeof(char));
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
	if (ft_strlen(map_raw) == 0)
	{
		free(map_raw);
		return(return_with_error("Empty map"));
	}
	game->map = ft_split(map_raw, '\n');
	//print_split(game->map);
	free(map_raw);
	if (map_is_valid(game) == -1)
		return(return_with_error("Invalid map"));
	
	return (0);
}

int	check_ber(char* map_path)
{
	int	len;
	
	len = ft_strlen(map_path);
	if (ft_strncmp(&map_path[len - 4], ".ber", 4) != 0)
	{
		return (-1);

	}
	return (0);
}

int		map_is_valid(t_game* game)
{

	int	line_length;
	int	line_count;
	int	player;
	int	exit;
	int enclosed;
	int	i;
	int	map_height;

	
	line_length = ft_strlen(game->map[0]);
	if (game->map == NULL)
		return(return_with_error("Empty file"));
	line_length = ft_strlen(*game->map);
	map_height = get_map_height(game->map);

	player = 0;
	exit = 0;
	enclosed = 0;
	line_count = 0;
	i = 0;
	game->collectibles = 0;


	while (game->map[line_count])
	{
		while (game->map[line_count][i])
		{
			if (ft_strlen(game->map[line_count]) != (size_t)line_length)
				return(return_with_error("Not rectangular map"));
			if ((line_count == 0 || line_count == map_height - 1 || i == 0 || i == line_length - 1) && game->map[line_count][i] != '1')
				return(return_with_error("Not enclosed map"));
			else if (game->map[line_count][i] == 'P')
			{
				game->player_x = i;
				game->player_y = line_count;
				player++;
			}
			else if (game->map[line_count][i] == 'E')
				exit++;
			else if (game->map[line_count][i] == 'C')
				game->collectibles++;
			else if (game->map[line_count][i] != '0' && game->map[line_count][i] != '1')
				return(return_with_error("Not allowed characters"));

			i++;
		}
		i = 0;
		line_count++;
	}
	
	map_height = line_count;
	if (player != 1 || exit != 1 || game->collectibles < 1)
		return(return_with_error("Wrong number of some elements"));
	printf("\nMAP_PARSE\n\tmap_h:\t%d\n\tmap_w:\t%d\n\tpla:\t%d\n\tex:\t%d\n\tcoll:\t%d\n\tlinlen:\t%d\n", map_height, line_length, player, exit, game->collectibles, line_length);
	return (0);



} 

int	get_map_height(char** map)
{
	int	i;

	i = 0;
	while(map[i])
	{
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







