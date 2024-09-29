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
	if (data->map_file != -1)
		close(data->map_file);
	ft_free_strtab(data->vemap->array);
	free(data->vemap);
	free(data->map);
	if (data->game_init)
	{
		mlx_destroy_window(data->game.mlx, data->game.win);
		mlx_destroy_image(data->game.mlx, data->game.img.img);
		mlx_destroy_image(data->game.mlx, data->game.minimap.img);
		mlx_destroy_display(data->game.mlx);
	}
	if (data->n)
		mlx_destroy_image(data->game.mlx, data->game.N.img);
	if (data->s)
		mlx_destroy_image(data->game.mlx, data->game.S.img);
	if (data->e)
		mlx_destroy_image(data->game.mlx, data->game.E.img);
	if (data->w)
		mlx_destroy_image(data->game.mlx, data->game.W.img);
	free(data->game.mlx);
}
