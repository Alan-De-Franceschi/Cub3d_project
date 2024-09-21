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
	if (nb_dot == -1)
		return (ft_free_parsing(data), EXIT_FAILURE);
	data->map = malloc(sizeof(t_map) * nb_dot + 1);
	if (!data->map)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	return (EXIT_SUCCESS);
}

int	ft_parse_map(t_vector *vector, t_program *data)
{
	if (ft_map_alloc(vector, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	
}