/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:19:03 by khatlas           #+#    #+#             */
/*   Updated: 2022/06/26 09:01:09 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_parse_x(va_list args, char *set)
{
	unsigned int	buffer;

	buffer = 0;
	buffer = va_arg(args, unsigned int);
	return (ft_itoa_base_u((unsigned long) buffer, set));
}
