/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:48:57 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/10 14:49:00 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_data	*init_game(t_data *game)
{
	if (!game->init_mlx.mlx)
		game->init_mlx.mlx = mlx_init();
	if (!game->init_mlx.mlx_win)
		game->init_mlx.mlx_win = mlx_new_window(game->init_mlx.mlx, \
				game->map->col * 32, (game->map->rows) * 32, "solong");
	return (game);
}
