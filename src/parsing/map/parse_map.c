/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:59:25 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 20:59:27 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	ft_max_len(char **array)
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

static int	ft_map_alloc(char **array, t_program *data)
{
	int	nb_line;

	nb_line = ft_count_line(array);
	data->game.map = ft_calloc(nb_line + 1, sizeof(char *));
	if (!data->game.map)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	return (EXIT_SUCCESS);
}

int	ft_parse_map(t_vector *vector, t_program *data)
{
	int	size;
	int	line_len;

	size = ft_count_line(vector->array);
	line_len = ft_max_len(vector->array);
	if (ft_map_validity(vector->array) == EXIT_FAILURE)
		return (ft_free_parsing(data), EXIT_FAILURE);
	if (ft_map_alloc(vector->array, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_map(vector->array, data, line_len,
			size) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->nb_column = ft_strlen(data->game.map[0]);
	data->nb_line = ft_strtab_len(data->game.map);
	return (EXIT_SUCCESS);
}
