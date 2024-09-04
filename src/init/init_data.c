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

void	ft_init_data(t_program *data)
{
	data->map_file = -1;
	data->n_path = NULL;
	data->s_path = NULL;
	data->e_path = NULL;
	data->w_path = NULL;
	data->f_colors = NULL;
	data->c_colors = NULL;
	data->parameters = 0;
	data->err = 0;
}
