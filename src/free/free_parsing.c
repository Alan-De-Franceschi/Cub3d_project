/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:49:19 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/04 17:49:20 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_parsing(t_program *data)
{

	// a check
	if (data->map_file != -1)
		close(data->map_file);
	ft_free_strtab(data->vemap->array);
	free(data->vemap);
	free(data->map);
}
