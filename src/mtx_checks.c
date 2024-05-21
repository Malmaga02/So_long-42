/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:16:20 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/04 14:16:23 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check_mtxlen(char **mtx, int col)
{
	int	rows;

	rows = 0;
	if (col < 3 || col > 30)
		return (free_mtx(mtx, col), 0);
	if (ft_strlen(mtx[rows]) < 3 || ft_strlen(mtx[rows]) > 36)
		return (free_mtx(mtx, col), 0);
	if (ft_strlen(mtx[rows]) == col)
		return (0);
	return (1);
}

int	check_walls(char **mtx)
{
	int	rows;
	int	col;

	rows = 0;
	while (mtx && mtx[rows])
	{
		if (rows > 0 && rows < count_rows(mtx) - 1)
		{
			col = ft_strlen(mtx[rows]) - 1;
			if (mtx[rows][0] != '1' || mtx[rows][col] != '1')
				return (0);
		}
		else
		{
			col = 0;
			while (mtx[rows][col])
			{
				if (mtx[rows][col] != '1')
					return (0);
				col++;
			}
		}
		rows++;
	}
	return (1);
}
