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
	while (s[i] != '\n' && s[i] != '\0')
		++i;
	return (i);
}

int	ft_max_len(char **array)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	len = 0;
	while (array[i])
	{
		len = ft_linelen(array[i]);
		if (len > max)
			max = len;
		++i;
	}
	return (max);
}

int	ft_count_dot(char **array)
{
	int	count;
	int	max_len;

	max_len = ft_max_len(array);
	count = ft_strtab_len(array) * max_len;
	return (count);
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
