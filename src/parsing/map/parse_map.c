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

static int	ft_map_alloc(char **array, t_program *data)
{
	int	nb_line;

	nb_line = ft_strtab_len(array);
	data->game.map = ft_calloc(nb_line + 1, sizeof(char *));
	if (!data->game.map)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	return (EXIT_SUCCESS);
}

int	ft_parse_map(t_vector *vector, t_program *data)
{
	data->nb_column = ft_max_len(vector->array);
	data->nb_line = ft_strtab_len(vector->array);
	if (ft_map_validity(vector->array) == EXIT_FAILURE)
		return (ft_free_parsing(data), EXIT_FAILURE);
	if (ft_map_alloc(vector->array, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_map(vector->array, data, data->nb_column,
			data->nb_line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
