/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:07 by mgalmari          #+#    #+#             */
/*   Updated: 2024/03/27 18:47:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_map	*game_map_control(char *argv)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->mtx = check_map(argv);
	if (!map->mtx)
		return (free(map), NULL);
	map = count_n_c(map);
	map->rows = count_rows(map->mtx);
	map->col = ft_strlen(map->mtx[0]);
	map = get_positions(map);
	if (!check_if_playable(map->mtx, map))
		return (free_mtx(map->mtx, count_rows(map->mtx)), free(map), NULL);
	return (map);
}

void	start_game(char	*argv)
{
	t_data	*game;

	game = ft_calloc(1, sizeof(t_data));
	if (!game)
		return ;
	game->player_moves = PLAYER_DOWN;
	game->moves = 0;
	game->map = game_map_control(argv);
	if (!game->map)
		return (free(game));
	game = init_game(game);
	game->map->img = get_img(game->init_mlx.mlx);
	if (!game->map->img)
		return (free_data(game));
	game_win_handling(game);
	mlx_hook(game->init_mlx.mlx_win, 17, (1L << 17), close_all, game);
	mlx_hook(game->init_mlx.mlx_win, 2, (1L << 0), my_key_hook, game);
	mlx_loop(game->init_mlx.mlx);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_strlen(av[1]) >= 5)
	{
		start_game(av[1]);
	}
	return (0);
}
