/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:11:47 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/15 15:11:53 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

t_data	*change_char(t_data *game)
{
	game->map->mtx[game->map->player_pos.y][game->map->player_pos.x] = 'P';
	return (game);
}

t_data	*change_pos(int y, int x, t_data *game)
{
	if (game->map->mtx[y][x] == '1')
	{
		game->moves -= 1;
		return (game);
	}
	game->map->player_pos.y = y;
	game->map->player_pos.x = x;
	return (game);
}

t_data	*key_handling(int keycode, t_data *game)
{
	int	x;

	x = game->map->player_pos.x;
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player_moves = PLAYER_UP;
		game = change_pos((game->map->player_pos.y - 1), x, game);
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player_moves = PLAYER_DOWN;
		game = change_pos((game->map->player_pos.y + 1), x, game);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player_moves = PLAYER_RIGHT;
		game = change_pos(game->map->player_pos.y, (x + 1), game);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player_moves = PLAYER_LEFT;
		game = change_pos(game->map->player_pos.y, (x - 1), game);
	}
	return (game);
}

t_data	*check_the_move(t_data *game)
{
	int	x;

	x = game->map->player_pos.x;
	if (game->map->mtx[game->map->player_pos.y][x] == 'C')
		game->map->collectibles -= 1;
	if (game->map->mtx[game->map->player_pos.y][x] == 'N')
	{
		ft_printf("Oh, the enemies got you.\nBe careful next time!\n");
		close_all(game);
	}
	if (game->map->collectibles == 0 && \
		game->map->player_pos.y == game->map->exit_pos.y && \
		x == game->map->exit_pos.x)
	{
		ft_printf("You won! Congratulations.\n");
		close_all(game);
	}
	return (game);
}

int	my_key_hook(int keycode, t_data *game)
{
	if (keycode == KEY_ESC)
		close_all(game);
	if (keycode == KEY_W || keycode == KEY_UP || keycode == KEY_S || \
		keycode == KEY_DOWN || keycode == KEY_D || keycode == KEY_RIGHT || \
		keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->map->mtx[game->map->player_pos.y][game->map->player_pos.x] = '0';
		game = key_handling(keycode, game);
		game = check_the_move(game);
		game = change_char(game);
		game->moves += 1;
		game_win_handling(game);
	}
	return (0);
}
