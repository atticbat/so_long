/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:57 by khatlas           #+#    #+#             */
/*   Updated: 2022/08/10 03:32:08 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_win(int keycode)
{
	if (keycode)
		;
	ft_printf("Game closed successfully\nLevel not completed\n");
	exit(0);
	return (0);
}

int	check_collision(t_player *player, t_ctrl *ctrl, t_v2 to, \
	int is_player)
{
	if (ctrl->battlefield[player->grid_loc.y + to.y] \
		[player->grid_loc.x + to.x] == '1')
		return (0);
	if (ctrl->battlefield[player->grid_loc.y + to.y] \
		[player->grid_loc.x + to.x] == 'C' && is_player)
	{
		ctrl->to_score--;
		ctrl->battlefield[player->grid_loc.y + to.y] \
			[player->grid_loc.x + to.x] = '0';
	}
	if (ctrl->battlefield[player->grid_loc.y + to.y] \
		[player->grid_loc.x + to.x] == 'E' && ctrl->to_score == 0 && is_player)
	{
		ft_printf("Victory!\nLevel finished in %d steps\n", ctrl->step_count);
		exit_game(ctrl);
	}
	if (!is_player && player->grid_loc.x == ctrl->player.grid_loc.x && \
		player->grid_loc.y == ctrl->player.grid_loc.y)
	{
		ft_printf("Game closed successfully\nYou got caught!\n");
		exit_game(ctrl);
	}
	return (1);
}

void	make_move(t_player *player, t_ctrl *ctrl, t_v2 grid_change, \
	t_v2 modes)
{
	player->grid_loc.y += grid_change.y;
	player->grid_loc.x += grid_change.x;
	player->to_move.y += (grid_change.y * 64);
	player->to_move.x += (grid_change.x * 64);
	player->mode = modes.x;
	if (modes.y)
		ctrl->step_count++;
}

int	button_press(int keycode, t_ctrl *ctrl)
{
	if (keycode == 53)
	{
		ft_printf("Game closed successfully\nLevel not completed\n");
		exit_game(ctrl);
		exit(0);
	}
	if (keycode == 13 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){0, -1}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){0, -1}, (t_v2) \
			{2, 1});
	if (keycode == 1 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){0, 1}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){0, 1}, (t_v2) \
			{3, 1});
	if (keycode == 0 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){-1, 0}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){-1, 0}, (t_v2) \
			{0, 1});
	if (keycode == 2 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){1, 0}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){1, 0}, (t_v2) \
			{1, 1});
	return (0);
}

void	move_enemy(t_ctrl *ctrl, int i)
{
	int	enemy_dir;

	enemy_dir = rand() % 4;
	if (enemy_dir == 2 && check_no_move(ctrl->enemies[i].to_move) && \
		check_collision(&(ctrl->enemies[i]), ctrl, (t_v2){0, -1}, 0))
		make_move(&(ctrl->enemies[i]), ctrl, (t_v2){0, -1}, (t_v2){2, 0});
	if (enemy_dir == 3 && check_no_move(ctrl->enemies[i].to_move) && \
		check_collision(&(ctrl->enemies[i]), ctrl, (t_v2){0, 1}, 0))
		make_move(&(ctrl->enemies[i]), ctrl, (t_v2){0, 1}, (t_v2){3, 0});
	if (enemy_dir == 0 && check_no_move(ctrl->enemies[i].to_move) && \
		check_collision(&(ctrl->enemies[i]), ctrl, (t_v2){-1, 0}, 0))
		make_move(&(ctrl->enemies[i]), ctrl, (t_v2){-1, 0}, (t_v2){0, 0});
	if (enemy_dir == 1 && check_no_move(ctrl->enemies[i].to_move) && \
		check_collision(&(ctrl->enemies[i]), ctrl, (t_v2){1, 0}, 0))
		make_move(&(ctrl->enemies[i]), ctrl, (t_v2){1, 0}, (t_v2){1, 0});
}
