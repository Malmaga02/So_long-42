/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:27:42 by mgalmari          #+#    #+#             */
/*   Updated: 2024/03/23 15:32:10 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./libft/headers/libft.h"
# include "mlx/mlx.h" 
# include <X11/keysym.h>
# include <X11/keysymdef.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

# define SPRITE_HEIGHT 32
# define SPRITE_WIDTH 32

typedef enum s_moves
{
	PLAYER_UP,
	PLAYER_DOWN,
	PLAYER_LEFT,
	PLAYER_RIGHT
}	t_moves;

typedef struct s_counter
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	count_n;
}		t_counter;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_coordinates
{
	int	x;
	int	y;
}		t_coordinates;

typedef struct s_img
{
	void	*player[4];
	void	*exit;
	void	*walls;
	void	*floor;
	void	*collectibles;
	void	*enemies;
}			t_img;

typedef struct s_map
{
	char			**mtx;
	int				rows;
	int				col;
	int				enemies;
	int				collectibles;
	t_img			*img;
	t_coordinates	player_pos;
	t_coordinates	exit_pos;
}					t_map;

typedef struct s_data
{
	t_mlx	init_mlx;
	t_map	*map;
	int		player_moves;
	int		moves;
}			t_data;

//main
void	start_game(char	*argv);
t_map	*game_map_control(char *argv);
// check_map 
int		read_file(char **join, int fd);
char	**get_map(char *arg_map, int *rows);
char	**check_map(char *arg_map);
// str_checks
int		check_path(char *arg_map);
int		check_read_file(char *join);
// mtx_checks
int		check_mtxlen(char **mtx, int j);
int		check_walls(char **mtx);
// get_positions
t_map	*find_position(t_map *map, int rows, int col);
t_map	*working_on_rows(t_map *map, int rows);
t_map	*get_positions(t_map *map);
// map_handling
t_map	*count_n_c(t_map *map);
// get_img
t_img	*get_img(void *mlx);
// playability
void	floodfill(char **mtx, int rows, int col);
int		check_full_space(char *str);
int		check_if_playable(char **mtx, t_map *map);
// init_game
t_data	*init_game(t_data *game);
// game_win_handling
void	exit_handling(t_data *game, int col, int rows);
void	player_handling(t_data *game, int col, int rows);
void	put_image(char c, int col, int rows, t_data *game);
void	game_win_handling(t_data *game);
// free_all
void	free_img(t_img *img, void *mlx);
void	free_map(t_map *map);
void	free_data(t_data *data);
int		close_all(t_data *data);
//key_hook
t_data	*change_pos(int y, int x, t_data *game);
t_data	*change_char(t_data *game);
t_data	*check_the_move(t_data *game);
t_data	*key_handling(int keycode, t_data *game);
int		my_key_hook(int keycode, t_data *data);
#endif
