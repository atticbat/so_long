/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:08:57 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/09 01:46:21 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(int keycode, t_ctrl *ctrl)
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
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		ft_printf("Victory!\nLevel finished in %d steps\n", ctrl->step_count);
		free_table(ctrl->battlefield, ctrl->map_dim);
		exit(0);
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
	{
		ctrl->step_count++;
		ft_printf("To score: %d, steps taken: %d\n", ctrl->to_score, \
			ctrl->step_count);
	}
}

int	button_press(int keycode, t_ctrl *ctrl)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ctrl->mlx, ctrl->win);
		ft_printf("Game closed successfully\nLevel not completed\n");
		free_table(ctrl->battlefield, ctrl->map_dim);
		exit(0);
	}
	if (keycode == 13 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){0, -1}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){0, -1}, (t_v2){2, 1});
	if (keycode == 1 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){0, 1}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){0, 1}, (t_v2){3, 1});
	if (keycode == 0 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){-1, 0}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){-1, 0}, (t_v2){0, 1});
	if (keycode == 2 && check_no_move(ctrl->player.to_move) && \
		check_collision(&(ctrl->player), ctrl, (t_v2){1, 0}, 1))
		make_move(&(ctrl->player), ctrl, (t_v2){1, 0}, (t_v2){1, 1});
	return (0);
}
