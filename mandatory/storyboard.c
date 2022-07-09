/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:26:24 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/06 02:06:26 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_next_frame(t_ctrl *ctrl)
{
	ctrl->cycle_count = (ctrl->cycle_count + 1) % 16;
	if (ctrl->cycle_count > 8)
		ctrl->player.frame = 1;
	else
		ctrl->player.frame = 0;
	mlx_clear_window (ctrl->mlx, ctrl->win);
	draw_field(ctrl);
	draw_sprite(&(ctrl->player), (t_rectangle){ctrl->player.bounds.x - \
		ctrl->offset.x, ctrl->player.bounds.y - ctrl->offset.y, 64, 64}, 'P', \
		ctrl);
	iterate_player(&ctrl->player);
	ctrl->offset.x = ctrl->player.bounds.x - 448;
	ctrl->offset.y = ctrl->player.bounds.y - 320;
	return (0);
}

void	iterate_player(t_player *player)
{
	if (player->to_move.x != 0)
	{
		player->bounds.x += player->to_move.x * player->move_speed / \
			ft_abs(player->to_move.x);
		player->to_move.x -= player->to_move.x * player->move_speed / \
			ft_abs(player->to_move.x);
	}
	if (player->to_move.y != 0)
	{
		player->bounds.y += player->to_move.y * player->move_speed / \
			ft_abs(player->to_move.y);
		player->to_move.y -= player->to_move.y * player->move_speed / \
			ft_abs(player->to_move.y);
	}
}

void	game_loop(t_ctrl *ctrl)
{
	mlx_hook(ctrl->win, 2, 1L << 0, button_press, ctrl);
	mlx_loop_hook(ctrl->mlx, render_next_frame, ctrl);
	mlx_hook(ctrl->win, 17, 0, close_win, ctrl);
	mlx_loop(ctrl->mlx);
}
