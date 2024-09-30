/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:37:13 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 13:37:15 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_init_ray(t_ray *ray, double planeX)
{
	ray->perpWallDist = 0;
	ray->wallX = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->lineHeight = 0;
	ray->Start = 0;
	ray->End = 0;
	ray->floorBegin = 0;
	ray->cellingBegin = 0;
	ray->res = WEIGHT / planeX;
	return ;
}

static void	ft_init_player(t_player *player)
{
	player->planeX = 320;
	player->position.x = 2.1;
	player->position.y = 4.1;
	player->fov = 60.0f;
	player->angle = 270.0f;
	player->speedMove = 200.0f;
	player->up = false;
	player->strafe_left = false;
	player->down = false;
	player->strafe_right = false;
	player->a = false;
	player->d = false;
	player->dir_x = 0;
	player->dir_y = 0;
	return ;
}



int	ft_init_game(t_program *data)
{
	// a proteger

	data->game.mlx = mlx_init();
	if (data->game.mlx == NULL)
		return (EXIT_FAILURE);
	data->game.win = mlx_new_window(data->game.mlx, WEIGHT, HEIGHT, "Cub3d");
	if (data->game.win == NULL)
		return (free(data->game.mlx), EXIT_FAILURE);
	ft_init_player(&data->game.player);
	data->game.minimap.img = mlx_new_image(data->game.mlx, 200, 200);
	if (data->game.minimap.img == NULL)
		return (free(data->game.mlx), free(data->game.win), 1);
	data->game.minimap.addr = (int *)mlx_get_data_addr(data->game.minimap.img,
			&data->game.minimap.bits_per_pixel, &data->game.minimap.line_length,
			&data->game.minimap.endian);
	data->game.img.img = mlx_new_image(data->game.mlx, WEIGHT, HEIGHT);
	data->game.img.addr = (int *)mlx_get_data_addr(data->game.img.img,
			&data->game.img.bits_per_pixel, &data->game.img.line_length,
			&data->game.img.endian);
	data->game.oldX = WEIGHT / 2;
	return (0);
}
