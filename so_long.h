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


typedef struct s_data
{
	void*	img;
	char*	addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

