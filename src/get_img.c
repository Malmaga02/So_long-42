/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:03:16 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/10 14:03:20 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_img	*get_img_player(void *mlx, t_img *img)
{
	int		height;
	int		width;

	height = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;
	img->player[0] = mlx_xpm_file_to_image(mlx, "textures/player_front.xpm", \
	&height, &width);
	img->player[1] = mlx_xpm_file_to_image(mlx, "textures/player_back.xpm", \
	&height, &width);
	img->player[2] = mlx_xpm_file_to_image(mlx, "textures/player_left.xpm", \
	&height, &width);
	img->player[3] = mlx_xpm_file_to_image(mlx, "textures/player_right.xpm", \
	&height, &width);
	return (img);
}

t_img	*get_img(void *mlx)
{
	t_img	*img;
	int		height;
	int		width;

	height = SPRITE_HEIGHT;
	width = SPRITE_WIDTH;
	img = ft_calloc(1, sizeof(t_img));
	img = get_img_player(mlx, img);
	img->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", \
	&height, &width);
	img->walls = mlx_xpm_file_to_image(mlx, "textures/walls.xpm", \
	&height, &width);
	img->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", \
	&height, &width);
	img->collectibles = mlx_xpm_file_to_image(mlx, "textures/collectible.xpm", \
	&height, &width);
	img->enemies = mlx_xpm_file_to_image(mlx, "textures/enemies.xpm", \
	&height, &width);
	return (img);
}

// controllo ritorno null u xpmfiletoimage destroy image
