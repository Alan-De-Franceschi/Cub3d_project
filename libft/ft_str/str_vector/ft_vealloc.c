/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vealloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:04:43 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 17:04:46 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vealloc(t_vector *vector)
{
	char	**new_array;
	size_t	i;

	i = 0;
	vector->capacity += 1;
	new_array = ft_calloc(vector->capacity + 1, sizeof(char *));
	if (!new_array)
		return (ft_free_strtab(vector->array), NULL);
	while (i < vector->size)
	{
		new_array[i] = vector->array[i];
		++i;
	}
	return (free(vector->array), new_array);
}
