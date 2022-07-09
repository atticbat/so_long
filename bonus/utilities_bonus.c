/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:15:07 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/09 02:13:45 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	free_enemies(t_player *enemies)
{
	if (!enemies)
		return ;
	free (enemies);
	enemies = NULL;
}

char	**free_table(char **table, t_v2 map_dim)
{
	int	i;

	i = 0;
	if (!table)
		return (NULL);
	while (i < map_dim.y)
	{
		free(table[i]);
		i++;
	}
	free(table);
	return (NULL);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else if (n == 0)
		return (1);
	return (n);
}

int	check_no_move(t_v2 to_move)
{
	if (to_move.x != 0)
		return (0);
	else if (to_move.y != 0)
		return (0);
	return (1);
}

void	exit_game(t_ctrl *ctrl)
{
	free_table(ctrl->battlefield, ctrl->map_dim);
	free_enemies(ctrl->enemies);
	mlx_destroy_window(ctrl->mlx, ctrl->win);
	exit(0);
}
