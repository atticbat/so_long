/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:03:06 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/09 01:59:46 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	init_battlefield(t_ctrl *ctrl, char *arg)
{
	ctrl->cycle_count = 0;
	ctrl->step_count = 0;
	ctrl->to_score = 0;
	ctrl->enemy_count = 0;
	ctrl->battlefield = generate_table(ctrl, arg);
}

static void	init_game(t_ctrl *ctrl)
{
	ctrl->mlx = mlx_init();
	ctrl->win = mlx_new_window(ctrl->mlx, 960, 640, "so_long");
	ctrl->enemies = spawn_enemies(ctrl);
	ctrl->tiles = initialise_tiles(ctrl->mlx);
	draw_field(ctrl);
}

int	main(int argc, char **argv)
{
	t_ctrl		ctrl;

	if (argc == 1)
	{
		ft_printf("Error\nmissing map\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_printf("Error\ntoo many arguments\n");
		return (0);
	}
	init_battlefield(&ctrl, argv[1]);
	if (!ctrl.battlefield)
	{
		ft_printf("Error\ninvalid map.\n");
		return (0);
	}
	init_game(&ctrl);
	game_loop(&ctrl);
	return (0);
}
