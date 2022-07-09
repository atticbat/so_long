/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_units.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:29:08 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 20:36:42 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
