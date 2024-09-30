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
	data->n = 0;
	data->s = 0;
	data->e = 0;
	data->w = 0;
	data->f_colors = 0;
	data->f = 0;
	data->c_colors = 0;
	data->c = 0;
	data->map_file = -1;
	data->map = NULL;
	data->map_size = 0;
	data->game_init = 0;
	data->game.mlx = NULL;
	data->vemap = ft_vinit();
	if (!data->vemap)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	data->game_init = 1;
	return (EXIT_SUCCESS);
}
