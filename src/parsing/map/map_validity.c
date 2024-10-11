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

static int	ft_check_empty_line(char **array, int nb_line)
{
	int	i;

	i = 0;
	while (i < nb_line)
	{
		if (ft_is_empty_line(array[i]))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	ft_map_validity(char **array)
{
	int	line;
	int	nb_line;
	int	start;
	int	i;

	line = 1;
	start = 0;
	i = 0;
	nb_line = ft_count_line(array);
	if (nb_line <= 2)
		return (ft_map_err(MAP_SIZE, 0, 0, 0));
	if (ft_check_empty_line(array, nb_line) == EXIT_FAILURE)
		return (ft_map_err(EMPTY_LINE, 0, 0, 0));
	while (i < nb_line)
	{
		if (ft_check_limits(line, nb_line, &start, array[i]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		++line;
		++i;
	}
	if (start != 1)
		return (ft_map_err(NO_START, start, line, 0));
	return (EXIT_SUCCESS);
}
