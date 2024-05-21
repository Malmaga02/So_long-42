/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:42:22 by mgalmari          #+#    #+#             */
/*   Updated: 2024/03/27 18:47:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	read_file(char **join, int fd)
{
	int		rows;
	char	*str;

	rows = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (ft_strncmp(str, "\n", 2) == 0)
		{
			if (*join)
				free(*join);
			return (free(str), 0);
		}
		*join = ft_freejoin(*join, str);
		if (!*join)
			return (free(str), 0);
		str = get_next_line(fd);
		rows++;
	}
	return (free(str), rows);
}

char	**get_map(char *arg_map, int *rows)
{
	int		fd;
	char	*join;

	fd = open(arg_map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	join = NULL;
	*rows = read_file(&join, fd);
	if (*rows == 0)
		return (close(fd), NULL);
	close(fd);
	if (!check_read_file(join))
		return (free(join), NULL);
	return (ft_split(join, '\n'));
}

char	**check_map(char *arg_map)
{
	int		i;
	int		rows;
	char	**mtx_map;

	i = 0;
	rows = 0;
	if (!check_path(arg_map))
		return (perror("Invalid file"), NULL);
	mtx_map = get_map(arg_map, &rows);
	if (!mtx_map || !check_mtxlen(mtx_map, rows))
		return (perror("Error on the reading"), NULL);
	while (mtx_map[i] && mtx_map[i + 1])
	{
		if (!ft_lencmp(mtx_map[i], mtx_map[i + 1]))
			return (free_mtx(mtx_map, rows), perror("Invalid map"), NULL);
		i++;
	}
	if (!check_walls(mtx_map))
		return (free_mtx(mtx_map, rows), perror("Invalid map"), NULL);
	return (mtx_map);
}
