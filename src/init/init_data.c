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

#include "cube.h"

int	ft_init_data(t_program *data)
{
	data->err = 0;
	data->parameters = 0;
	data->n_path = NULL;
	data->s_path = NULL;
	data->e_path = NULL;
	data->w_path = NULL;
	data->f_colors = NULL;
	data->c_colors = NULL;
	data->map_file = -1;
	data->vemap = ft_vinit();
	if (!data->vemap)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	data->map = NULL;
	return (EXIT_SUCCESS);
}
