/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:46:00 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/27 15:46:01 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_data(t_program *data)
{
	data->err = 0;
	data->bonus = 0;
	data->parameters = 0;
	data->n_path = NULL;
	data->n = 0;
	data->s_path = NULL;
	data->s = 0;
	data->e_path = NULL;
	data->e = 0;
	data->w_path = NULL;
	data->w = 0;
	data->f_colors = 0;
	data->f = 0;
	data->c_colors = 0;
	data->c = 0;
	data->map_file = -1;
	data->map = NULL;
	data->map_size = 0;
	data->vemap = ft_vinit();
	if (!data->vemap)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	if (ft_init_game(&data->game) == EXIT_FAILURE)
		return (EXIT_FAILURE); // gestion erreur
	return (EXIT_SUCCESS);
}
