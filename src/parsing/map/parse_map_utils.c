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

#include "cub3d.h"

int	ft_is_empty_line(char *line)
{
	while (*line == ' ' || *line == 9)
		line++;
	if (*line == '\n' || *line == '\0')
		return (1);
	else
		return (0);
}

int	ft_hlimit(char *str, int line)
{
	while (*str != '\n' && *str != '\0')
	{
		if (!ft_in_charset(" 1", *str))
			return (ft_map_err(NOT_CLOSED, 0, line, *str));
		++str;
	}
	return (EXIT_SUCCESS);
}

int	ft_vlimit(char *str, int line, int *start)
{
	while (*str == ' ')
	{
		if (*str == 9)
			return (ft_map_err(INV_CHAR, 0, line, *str));
		++str;
	}
	if (*str != '1')
		return (ft_map_err(NOT_CLOSED, 0, line, *str));
	while (!ft_in_charset("\n\0", *str))
	{
		if (!ft_in_charset("01NSEW ", *str))
			return (ft_map_err(INV_CHAR, 0, line, *str));
		if (ft_in_charset("NSEW", *str))
			*start += 1;
		++str;
	}
	while (ft_in_charset(" \n\0", *str))
		--str;
	if (*str != '1')
		return (ft_map_err(NOT_CLOSED, *start, line, *str));
	return (EXIT_SUCCESS);
}

int	ft_count_line(char **array)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (array[i])
	{
		if (!ft_is_empty_line(array[i]))
			++count;
		++i;
	}
	return (count);
}
