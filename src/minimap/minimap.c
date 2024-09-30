/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:24:32 by jaung             #+#    #+#             */
/*   Updated: 2024/09/23 14:24:34 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_minimap(t_program *data)
{
	ft_draw_minimap(data);
	mlx_put_image_to_window(data->game.mlx, data->game.win, data->game.minimap.img, 0, 0);
	return ;
}
