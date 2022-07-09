/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:36:50 by khatlas           #+#    #+#             */
/*   Updated: 2022/06/26 09:01:56 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static char	*right_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = NULL;
	len = ft_strlen(buffer);
	ptr = (char *) malloc (sizeof(char) * (to_malloc + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ft_memcpy(ptr + i, buffer, len);
	i += len;
	ptr[i] = '\0';
	return (ptr);
}

static char	*left_just(t_parse *data, char pad, char *buffer, int to_malloc)
{
	char	*ptr;
	int		i;
	int		len;

	ptr = NULL;
	len = (int) ft_strlen(buffer);
	i = 0;
	ptr = (char *) malloc (sizeof(char) * (to_malloc + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr + i, buffer, len);
	i += len;
	ft_memset(ptr + i, pad, data->width);
	i += data->width;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_format_pp(t_parse *data)
{
	char	pad;
	char	*buffer;
	int		to_malloc;

	pad = ' ';
	buffer = NULL;
	buffer = data->arg_str;
	data->width -= 1;
	if (data->width < 0)
		data->width = 0;
	to_malloc = data->width + 1;
	if (data->justi_zero == '0')
		pad = '0';
	if (data->justi_zero == '-')
		return (left_just(data, pad, buffer, to_malloc));
	return (right_just(data, pad, buffer, to_malloc));
}
