/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:19:56 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 19:41:26 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*choose_img(t_player *player, char type, t_ctrl *ctrl)
{
	if (type == '0')
		return (ctrl->tiles.path);
	else if (type == '1')
		return (ctrl->tiles.wall);
	else if (type == 'E')
		return (ctrl->tiles.exit);
	else if (type == 'P' && check_no_move(player->to_move))
		return (ctrl->tiles.player.idle[player->mode][player->frame]);
	else if (type == 'P' && !check_no_move(player->to_move))
		return (ctrl->tiles.player.move[player->mode][player->frame]);
	else if (type == 'T' && check_no_move(player->to_move))
		return (ctrl->tiles.enemy.idle[player->mode][player->frame]);
	else if (type == 'T' && !check_no_move(player->to_move))
		return (ctrl->tiles.enemy.move[player->mode][player->frame]);
	else if (type == 'C')
		return (ctrl->tiles.coin);
	return (ctrl->tiles.path);
}

void	draw_sprite(t_player *player, t_rectangle bounds, char type, t_ctrl \
	*ctrl)
{
	int		width;

	width = 64;
	mlx_put_image_to_window(ctrl->mlx, ctrl->win, choose_img(player, type, \
		ctrl), bounds.x, bounds.y);
}

void	draw_field(t_ctrl *ctrl)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = ctrl->player.grid_loc.x;
	y = ctrl->player.grid_loc.y;
	i = x - 8;
	if (i < 0)
		i = 0;
	while (i < ctrl->map_dim.x && i < x + 9)
	{
		j = y - 6;
		if (j < 0)
			j = 0;
		while (j < ctrl->map_dim.y && j < y + 6)
		{
			draw_sprite(NULL, (t_rectangle){(i * 64) - ctrl->offset.x, \
				(j * 64) - ctrl->offset.y, 64, 64}, ctrl->battlefield[j][i], \
				ctrl);
			j++;
		}
		i++;
	}
}
