/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:03:58 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 17:04:00 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vinit(void)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->capacity = 5;
	vector->size = 0;
	vector->array = ft_calloc(vector->capacity + 1, sizeof(char *));
	if (!vector->array)
		return (free(vector), NULL);
	return (vector);
}
