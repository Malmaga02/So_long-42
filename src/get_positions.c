/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:32 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/04 16:02:36 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_map	*find_position(t_map *map, int rows, int col)
{
	if (map->mtx[rows][col] == 'P')
	{
		map->player_pos.x = col;
		map->player_pos.y = rows;
	}
	if (map->mtx[rows][col] == 'E')
	{
		map->exit_pos.x = col;
		map->exit_pos.y = rows;
	}
	return (map);
}

t_map	*working_on_rows(t_map *map, int rows)
{
	int	col;

	col = 0;
	while (map->mtx[rows] && map->mtx[rows][col])
	{
		if (map->mtx[rows][col] == 'P' || map->mtx[rows][col] == 'E')
			map = find_position(map, rows, col);
		if (!map)
			return (NULL);
		col++;
	}
	return (map);
}

t_map	*get_positions(t_map *map)
{
	int	rows;

	rows = 0;
	while (map->mtx && map->mtx[rows])
	{
		map = working_on_rows(map, rows);
		if (!map)
			return (NULL);
		rows++;
	}
	return (map);
}
