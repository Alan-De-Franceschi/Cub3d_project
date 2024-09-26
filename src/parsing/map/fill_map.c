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

#include "cube.h"

static void	ft_check_start(char c, int x, int y, t_program *data)
{
	if (ft_in_charset("NSEW", c))
	{
		data->start_x = x;
		data->start_y = y;
		data->start = c;
	}
}

static void	ft_fill_line(t_map *dot, char c, int *x, int y)
{
	dot->x = *x;
	dot->y = y;
	if (c == ' ')
		dot->value = '1';
	else
		dot->value = c;
	++(*x);
}

static void	ft_fill_end_of_line(t_map *dot, int *i, int *x, int y)
{
	dot->x = *x;
	dot->y = y;
	dot->value = '1';
	++(*i);
	++(*x);
}

void	ft_fill_map(char **array, t_program *data, int line_len)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (array[y])
	{
		x = 0;
		while (x < line_len)
		{
			if (array[y][x] == '\0' || array[y][x] == '\n')
			{
				while (x < line_len)
					ft_fill_end_of_line(&data->map[i], &i, &x, y);
			}
			else
			{
				ft_check_start(array[y][x], x, y, data);
				ft_fill_line(&data->map[i], array[y][x], &x, y);
				++i;
			}
		}
		++y;
	}
}
