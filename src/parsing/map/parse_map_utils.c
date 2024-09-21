/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:24:55 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 23:24:57 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_linelen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (s[i] == 9)
			return (-1);
		++i;
	}
	return (i);
}

static int	ft_max_len(char **array)
{
	int	i;
	int	max;
	int len;
	int	line;

	i = 0;
	max = 0;
	len = 0;
	line = 1;
	while (array[i])
	{
		len = ft_linelen(array[i]);
		if (len = -1)
		{
			ft_printf("Error\nMap: Tab on line %d\n", 2, line);
			return (-1);
		}
		if (len > max)
			max = len;
		++i;
		++line;
	}
	return (max);
}

int	ft_count_dot(char **array)
{
	int count;
	int max_len;

	max_len = ft_max_len(array);
	if (max_len == -1)
		return (-1);
	count = ft_strtab_len(array) * max_len;
	return (count);
}
