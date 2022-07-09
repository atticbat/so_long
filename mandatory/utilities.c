/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:15:07 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/05 06:08:44 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
