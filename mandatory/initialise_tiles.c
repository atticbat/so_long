/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:09:04 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 20:36:14 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_player_idle(t_tiles *tiles, void *mlx)
{
	int		width;

	width = 64;
	tiles->player.idle[0][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/LI1.xpm", &width, &width);
	tiles->player.idle[0][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/LI2.xpm", &width, &width);
	tiles->player.idle[1][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/RI1.xpm", &width, &width);
	tiles->player.idle[1][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/RI2.xpm", &width, &width);
	tiles->player.idle[2][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/UI1.xpm", &width, &width);
	tiles->player.idle[2][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/UI2.xpm", &width, &width);
	tiles->player.idle[3][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/DI1.xpm", &width, &width);
	tiles->player.idle[3][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/DI2.xpm", &width, &width);
}

static void	set_player_move(t_tiles *tiles, void *mlx)
{
	int		width;

	width = 64;
	tiles->player.move[0][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/LM1.xpm", &width, &width);
	tiles->player.move[0][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/LM2.xpm", &width, &width);
	tiles->player.move[1][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/RM1.xpm", &width, &width);
	tiles->player.move[1][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/RM2.xpm", &width, &width);
	tiles->player.move[2][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/UM1.xpm", &width, &width);
	tiles->player.move[2][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/UM2.xpm", &width, &width);
	tiles->player.move[3][0] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/DM1.xpm", &width, &width);
	tiles->player.move[3][1] = mlx_xpm_file_to_image (mlx, \
		"resources/sprites/DM2.xpm", &width, &width);
}

t_tiles	initialise_tiles(void *mlx)
{
	t_tiles	tiles;
	int		width;

	width = 64;
	tiles.wall = mlx_xpm_file_to_image (mlx, "resources/1.xpm", &width, &width);
	tiles.path = mlx_xpm_file_to_image (mlx, "resources/0.xpm", &width, &width);
	tiles.coin = mlx_xpm_file_to_image (mlx, "resources/C.xpm", &width, &width);
	tiles.exit = mlx_xpm_file_to_image (mlx, "resources/E.xpm", &width, &width);
	set_player_idle(&tiles, mlx);
	set_player_move(&tiles, mlx);
	return (tiles);
}
