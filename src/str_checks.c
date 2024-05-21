/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:46:58 by mgalmari          #+#    #+#             */
/*   Updated: 2024/03/27 18:47:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	check_path(char *arg_map)
{
	int	i;

	i = ft_strlen(arg_map) - 4;
	if (ft_strncmp(&arg_map[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	check_char_count(t_counter count_char)
{
	if (count_char.count_p >= 2 || count_char.count_e >= 2)
		return (0);
	if (count_char.count_p == 0 || count_char.count_e == 0 || \
			count_char.count_c == 0)
		return (0);
	return (1);
}

static void	char_count(char c, t_counter *count_char)
{
	if (c == 'P')
		(count_char->count_p)++;
	if (c == 'C')
		(count_char->count_c)++;
	if (c == 'E')
		(count_char->count_e)++;
}

int	check_read_file(char *join)
{
	t_counter	count_char;
	int			i;

	count_char = (t_counter){0};
	i = 0;
	while (join && join[i])
	{
		if (join[i] == '1' || join[i] == '0' || join[i] == 'E' || \
		join[i] == 'C' || join[i] == 'P' || join[i] == 'N' || join[i] == '\n')
		{
			if (join[i] == 'P' || join[i] == 'E' || join[i] == 'C')
				char_count(join[i], &count_char);
			i++;
		}
		else
			return (0);
	}
	if (!check_char_count(count_char))
		return (0);
	return (1);
}
