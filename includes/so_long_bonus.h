/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 04:09:06 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 03:31:29 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define GL_SILENCE_DEPRECATION
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"

typedef struct s_rectangle
{
	int	x;
	int	y;
	int	width;
	int	height;
}		t_rectangle;

typedef struct s_vector_2
{
	int	x;
	int	y;
}		t_v2;

typedef struct s_player
{
	t_rectangle	bounds;
	t_v2		grid_loc;
	t_v2		to_move;
	int			mode;
	int			frame;
	int			move_speed;
}				t_player;

typedef struct s_sprite
{
	void	*idle[4][2];
	void	*move[4][2];
}			t_sprite;

typedef struct s_tiles
{
	void		*wall;
	void		*path;
	void		*coin;
	void		*exit;
	t_sprite	player;
	t_sprite	enemy;
}				t_tiles;

typedef struct s_ctrl
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_v2		map_dim;
	char		**battlefield;
	int			cycle_count;
	int			step_count;
	int			to_score;
	t_tiles		tiles;
	t_v2		offset;
	t_player	*enemies;
	int			enemy_count;
}				t_ctrl;

t_tiles		initialise_tiles(void *mlx);
char		**generate_table(t_ctrl *ctrl, char *argv);
int			button_press(int keycode, t_ctrl *ctrl);
int			close_win(int keycode);
int			ft_abs(int n);
int			check_no_move(t_v2 to_move);
void		draw_field(t_ctrl *ctrl);
t_player	initialise_player(t_v2 grid_loc);
void		iterate_player(t_player *player);
int			render_next_frame(t_ctrl *ctrl);
void		draw_sprite(t_player *player, t_rectangle bounds, char type, \
	t_ctrl *ctrl);
char		**free_table(char **table, t_v2 map_dim);
t_player	*spawn_enemies(t_ctrl *ctrl);
int			check_collision(t_player *player, t_ctrl *ctrl, t_v2 \
	to_loc,	int is_player);
void		make_move(t_player *player, t_ctrl *ctrl, t_v2 grid_change, \
	t_v2 modes);
int			ft_linelen(const char *str);
void		game_loop(t_ctrl *ctrl);
void		move_enemy(t_ctrl *ctrl, int i);
void		exit_game(t_ctrl *ctrl);

#endif
