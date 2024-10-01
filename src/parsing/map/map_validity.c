/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:54:54 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/25 17:54:56 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_limits(int line, int size, int *start, char *str)
{
	if (line == 1 || line == size)
	{
		if (ft_hlimit(str, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		if (ft_vlimit(str, line, start) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_map_validity(char **array)
{
	int	line;
	int	size;
	int	start;

	line = 1;
	start = 0;
	size = ft_strtab_len(array);
	if (size <= 2)
		return (ft_map_err(MAP_SIZE, 0, 0, 0));
	while (*array)
	{
		if (ft_check_limits(line, size, &start, *array) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		++line;
		++array;
	}
	if (start != 1)
		return (ft_map_err(NO_START, start, line, 0));
	return (EXIT_SUCCESS);
}
