/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:58:05 by khatlas           #+#    #+#             */
/*   Updated: 2022/06/26 09:46:07 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static char	*choose_format(t_parse *data)
{
	if (data->type == 'c')
		return (ft_format_c(data));
	else if (data->type == 's')
		return (ft_format_s(data));
	else if (data->type == 'x' || data->type == 'X')
		return (ft_format_x(data));
	else if (data->type == '%')
		return (ft_format_pp(data));
	else if (ft_strchr("pdiu", data->type))
		return (ft_format_i(data));
	return (NULL);
}

static int	put_c(const char *s, int len)
{
	write (1, s, len);
	return (len);
}

static int	print(t_parse *data)
{
	size_t	len;
	char	*buffer;
	char	*buffer2;

	len = 1;
	buffer = NULL;
	buffer2 = NULL;
	buffer = choose_format(data);
	buffer2 = data->arg_str;
	if (data->type == 'c')
		len = put_c(buffer, data->width);
	else
	{
		ft_putstr_fd(buffer, 1);
		len = ft_strlen(buffer);
	}
	if (buffer != buffer2)
		free(buffer);
	free(buffer2);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		n;
	t_parse	*data;

	n = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			data = parse (&str, args);
			if (!(data))
				return (n);
			n += print (data);
			free(data);
		}
		else
			n += put_c (str, 1);
		str++;
	}	
	va_end(args);
	return (n);
}
// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*str = "";
// 	// printf("% s\n", str);
// 	ft_printf("% s\n", str);
// 	// system("leaks a.out");
// 	return (0);
// }
