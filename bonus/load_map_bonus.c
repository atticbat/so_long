/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khatlas < khatlas@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:04:36 by khatlas           #+#    #+#             */
/*   Updated: 2022/07/06 02:05:49 by khatlas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	**ft_append(char **table, char *str, int length)
{
	char	**out;

	out = (char **) malloc (sizeof (char *) * (length + 1));
	out[length] = str;
	while (length - 1 > 0)
	{
		out[length - 1] = ft_strdup(table[length - 1]);
		free(table[length - 1]);
		length--;
	}
	out[0] = ft_strdup(table[0]);
	free(table[0]);
	free(table);
	table = NULL;
	return (out);
}

static int	check_content(char *row, int i, t_ctrl *ctrl, t_v2 *counts)
{
	int	j;

	j = 0;
	while (j <= ctrl->map_dim.x)
	{
		if (row[j] == 'P')
		{
			ctrl->player = initialise_player((t_v2){j, i});
			ctrl->offset.x = 64 * j - 448;
			ctrl->offset.y = 64 * i - 320;
			(counts->x)++;
			row[j] = '0';
		}
		else if (row[j] == 'C')
			ctrl->to_score++;
		else if (row[j] == 'E')
			(counts->y)++;
		else if (row[j] == 'T')
			ctrl->enemy_count++;
		else if (!ft_strchr("01\n", row[j]))
			return (0);
		j++;
	}
	return (1);
}

static int	parse_table(char **table, t_v2 map_dim)
{
	int	i;

	i = 0;
	while (i < map_dim.x)
	{
		if (table[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_dim.x)
	{
		if (table[map_dim.y - 1][i] != '1')
			return (0);
		i++;
	}
	while (map_dim.y - 1 >= 1)
	{
		if (table[map_dim.y - 1][0] != '1')
			return (0);
		if (table[map_dim.y - 1][map_dim.x - 1] != '1')
			return (0);
		map_dim.y--;
	}
	return (1);
}

static char	**build_table(t_ctrl *ctrl, int fd, t_v2 *counts)
{
	char	**new_table;
	char	*buffer;
	int		i;

	new_table = (char **) malloc (sizeof(char *));
	new_table[0] = get_next_line(fd);
	ctrl->map_dim.x = ft_linelen(*new_table);
	i = 0;
	while (1)
	{
		if (check_content(new_table[i], i, ctrl, counts) == 0)
			return (free_table(new_table, (t_v2){ctrl->map_dim.x, i + 1}));
		i++;
		buffer = get_next_line(fd);
		if (ft_linelen(buffer) != -1 && ft_linelen(buffer) != ctrl->map_dim.x)
		{
			free (buffer);
			return (free_table(new_table, (t_v2){ctrl->map_dim.x, i}));
		}
		new_table = ft_append(new_table, buffer, i);
		if (!new_table[i])
			break ;
	}
	ctrl->map_dim.y = i;
	return (new_table);
}

char	**generate_table(t_ctrl *ctrl, char *argv)
{
	char	**new_table;
	int		fd;
	int		i;
	char	*buffer;
	t_v2	counts;

	counts = (t_v2){0, 0};
	i = ft_strlen(argv) - 1;
	if (argv[i - 3] != '.' || argv[i - 2] != 'b' || argv[i - 1] != 'e' || \
		argv[i] != 'r')
		return (NULL);
	buffer = ft_strjoin("levels/", argv);
	fd = open(buffer, O_RDONLY);
	free (buffer);
	if (fd == -1)
		return (NULL);
	new_table = build_table(ctrl, fd, &counts);
	if (!new_table)
		return (NULL);
	if (!parse_table(new_table, ctrl->map_dim) || counts.x != 1 || \
		counts.y != 1 || ctrl->to_score < 1)
		return (free_table(new_table, ctrl->map_dim));
	close (fd);
	return (new_table);
}
