/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_win_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:29:34 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/10 15:29:38 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	player_handling(t_data *game, int col, int rows)
{
	int	move;

	move = game->player_moves;
	if (move == PLAYER_DOWN)
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
			game->map->img->player[0], col * 32, rows * 32);
	if (move == PLAYER_UP)
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
			game->map->img->player[1], col * 32, rows * 32);
	if (move == PLAYER_LEFT)
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
			game->map->img->player[2], col * 32, rows * 32);
	if (move == PLAYER_RIGHT)
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
			game->map->img->player[3], col * 32, rows * 32);
}

void	exit_handling(t_data *game, int col, int rows)
{
	if (game->map->collectibles == 0)
	{
		col = game->map->exit_pos.x;
		rows = game->map->exit_pos.y;
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->exit, col * 32, rows * 32);
	}
	else
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->floor, col * 32, rows * 32);
}

void	put_image(char c, int col, int rows, t_data *game)
{
	if (c == '1')
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->walls, col * 32, rows * 32);
	if (c == '0')
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->floor, col * 32, rows * 32);
	if (c == 'C')
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->collectibles, col * 32, rows * 32);
	if (c == 'N')
		mlx_put_image_to_window(game->init_mlx.mlx, game->init_mlx.mlx_win, \
		game->map->img->enemies, col * 32, rows * 32);
	if (c == 'P')
		player_handling(game, col, rows);
	if (c == 'E' || game->map->collectibles == 0)
		exit_handling(game, col, rows);
}

void	game_win_handling(t_data *game)
{
	int		rows;
	int		col;
	char	*moves;

	rows = 0;
	while (game->map->mtx && game->map->mtx[rows])
	{
		col = 0;
		while (game->map->mtx[rows] && game->map->mtx[rows][col])
		{
			put_image(game->map->mtx[rows][col], col, rows, game);
			col++;
		}
		rows++;
	}
	moves = ft_itoa(game->moves);
	mlx_string_put(game->init_mlx.mlx, game->init_mlx.mlx_win, 5, \
	rows, 0xFFFEEF, "MOVES:");
	mlx_string_put(game->init_mlx.mlx, game->init_mlx.mlx_win, 50, \
	rows, 0xFFFEEF, moves);
	free(moves);
}
