/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:51:49 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 18:51:50 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

void	end_game(t_program *data)
{
	mlx_destroy_window(&data->game.mlx, &data->game.win);
	mlx_destroy_image(&data->game.mlx, &data->game.img.img);
	mlx_destroy_image(&data->game.mlx, &data->game.minimap.img);
	mlx_destroy_image(&data->game.mlx, &data->game.E.img);
	mlx_destroy_image(&data->game.mlx, &data->game.W.img);
	mlx_destroy_image(&data->game.mlx, &data->game.S.img);
	mlx_destroy_image(&data->game.mlx, &data->game.N.img);
	mlx_destroy_display(&data->game.mlx);
	free(data->game.mlx);
	ft_free_parsing(data);
	exit(0);
}
