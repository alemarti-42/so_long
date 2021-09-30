/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <alemarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:45:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/30 17:59:08 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	ft_putstr_fd("\tBUG\n", 0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ft_putstr_fd("\tBUG\n", 0);
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		res[i] = s1[i];
	j = i ;
	i = -1;
	while (s2[++i])
		res[j + i] = s2[i];
	res[j + i] = 0;
	return (res);
}
