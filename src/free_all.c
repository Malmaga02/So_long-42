/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:57:53 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/15 11:57:55 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	free_img(t_img *img, void *mlx)
{
	mlx_destroy_image(mlx, img->player[0]);
	mlx_destroy_image(mlx, img->player[1]);
	mlx_destroy_image(mlx, img->player[2]);
	mlx_destroy_image(mlx, img->player[3]);
	mlx_destroy_image(mlx, img->walls);
	mlx_destroy_image(mlx, img->floor);
	mlx_destroy_image(mlx, img->enemies);
	mlx_destroy_image(mlx, img->collectibles);
	mlx_destroy_image(mlx, img->exit);
	free(img);
}

void	free_map(t_map *map)
{
	free_mtx(map->mtx, count_rows(map->mtx));
	free(map);
}

void	free_data(t_data *data)
{
	free_map(data->map);
	free(data);
}

int	close_all(t_data *game)
{
	free_img(game->map->img, game->init_mlx.mlx);
	mlx_destroy_window(game->init_mlx.mlx, game->init_mlx.mlx_win);
	mlx_destroy_display(game->init_mlx.mlx);
	free(game->init_mlx.mlx);
	free_data(game);
	exit(0);
	return (0);
}
