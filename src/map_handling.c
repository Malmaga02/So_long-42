_/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:46:44 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/15 10:46:47 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_map	*count_n_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mtx && map->mtx[i])
	{
		j = 0;
		while (map->mtx[i] && map->mtx[i][j])
		{
			if (map->mtx[i][j] == 'N')
				map->enemies++;
			if (map->mtx[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	return (map);
}
