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

#include "cube.h"

static int	ft_map_alloc(t_vector *vector, t_program *data)
{
	int	nb_dot;

	nb_dot = ft_count_dot(vector->array);
	data->map_size = nb_dot;
	ft_printf("\nNb_dot = %d\n\n", 1, nb_dot);
	data->map = ft_calloc(nb_dot, sizeof(t_map));
	if (!data->map)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	return (EXIT_SUCCESS);
}

int	ft_parse_map(t_vector *vector, t_program *data)
{
	int	line_len;

	line_len = ft_max_len(vector->array);
	if (ft_map_validity(vector->array) == EXIT_FAILURE)
		return (ft_free_parsing(data), EXIT_FAILURE);
	if (ft_map_alloc(vector, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_fill_map(vector->array, data, line_len);
	return (EXIT_SUCCESS);
}
