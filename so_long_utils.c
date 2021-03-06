/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:42:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/10/06 18:34:11 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(char *str, t_game *game)
{
	game_destroy(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (1);
}

int	return_with_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	return (-1);
}
