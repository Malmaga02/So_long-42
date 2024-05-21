/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playability.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:24:18 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/04 16:24:28 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check_full_space(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'E' || str[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

void	floodfill(char **mtx, int rows, int col)
{
	if (mtx[rows][col] == '1' || mtx[rows][col] == 'X' || mtx[rows][col] == 'N')
		return ;
	mtx[rows][col] = 'X';
	floodfill(mtx, rows, col + 1);
	floodfill(mtx, rows, col - 1);
	floodfill(mtx, rows + 1, col);
	floodfill(mtx, rows - 1, col);
}

int	check_if_playable(char **mtx, t_map *map)
{
	char	**mtx_cpy;
	int		col;
	int		rows;
	int		i;

	i = 0;
	rows = map->player_pos.y;
	col = map->player_pos.x;
	mtx_cpy = ft_mtxdup(mtx);
	if (!mtx_cpy)
		return (free_mtx(mtx_cpy, count_rows(mtx_cpy)), 0);
	floodfill(mtx_cpy, rows, col);
	while (mtx_cpy && mtx_cpy[i])
	{
		if (!check_full_space(mtx_cpy[i]))
			return (free_mtx(mtx_cpy, count_rows(mtx_cpy)), 0);
		i++;
	}
	return (free_mtx(mtx_cpy, count_rows(mtx_cpy)), 1);
}
