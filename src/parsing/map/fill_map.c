/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:13:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/25 18:13:30 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_start(char c, int x, int y, t_program *data)
{
	if (ft_in_charset("NSEW", c))
	{
		data->start_x = x;
		data->start_y = y;
		data->start = c;
	}
}

static void	ft_fill_end_of_line(char *str, int *x, int line_len)
{
	while (*x < line_len)
	{
		str[*x] = '1';
		++(*x);
	}
}

static void	ft_fill_line(t_program *data, char *str, int *x, int y)
{
	ft_check_start(data->vemap->array[y][*x], *x, y, data);
	if (data->vemap->array[y][*x] == ' ')
		str[*x] = '1';
	else
		str[*x] = data->vemap->array[y][*x];
	++(*x);
}

int	ft_fill_map(char **array, t_program *data, int line_len, int nb_line)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	while (y < nb_line)
	{
		x = 0;
		str = malloc(sizeof(char) * line_len + 1);
		if (!str)
			return (ft_parsing_err(MEM_ERR, NULL, data));
		str[line_len] = '\0';
		while (x < line_len)
		{
			if (array[y][x] == '\0' || array[y][x] == '\n')
				ft_fill_end_of_line(str, &x, line_len);
			else
				ft_fill_line(data, str, &x, y);
		}
		data->game.map[y] = str;
		str = NULL;
		++y;
	}
	data->game.map[nb_line] = NULL;
	return (EXIT_SUCCESS);
}
