/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:05:28 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 17:05:29 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vadd(t_vector *vector, char *element)
{
	if (vector->size == vector->capacity)
	{
		vector->array = ft_vealloc(vector);
		if (!vector->array)
		{
			free(vector);
			vector = NULL;
			return (EXIT_FAILURE);
		}
		vector->array[vector->size] = element;
	}
	else
		vector->array[vector->size] = element;
	++vector->size;
	vector->array[vector->capacity] = NULL;
	return (EXIT_SUCCESS);
}
