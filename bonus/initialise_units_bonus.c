/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_units_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:29:08 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 19:42:50 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_player	initialise_player(t_v2 loc)
{
	t_player	player;

	player.bounds.x = 64 * loc.x;
	player.bounds.y = 64 * loc.y;
	player.bounds.width = 64;
	player.bounds.height = 64;
	player.grid_loc.x = loc.x;
	player.grid_loc.y = loc.y;
	player.to_move.x = 0;
	player.to_move.y = 0;
	player.mode = 3;
	player.frame = 0;
	player.move_speed = 4;
	return (player);
}

static t_v2	find_enemy(char **battlefield, t_v2 map_dim)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_dim.x)
	{
		j = 0;
		while (j < map_dim.y)
		{
			if (battlefield[j][i] == 'T')
				return ((t_v2){i, j});
			j++;
		}
		i++;
	}
	return ((t_v2){0, 0});
}

t_player	*spawn_enemies(t_ctrl *ctrl)
{
	t_player	*enemies;
	int			i;
	t_v2		enemy_loc;

	enemies = (t_player *) malloc (sizeof(t_player) * ctrl->enemy_count);
	if (!enemies)
		return (NULL);
	i = ctrl->enemy_count - 1;
	while (i >= 0)
	{
		enemy_loc = find_enemy(ctrl->battlefield, ctrl->map_dim);
		enemies[i] = initialise_player(enemy_loc);
		enemies[i].move_speed = 2;
		ctrl->battlefield[enemy_loc.y][enemy_loc.x] = '0';
		i--;
	}
	return (enemies);
}
