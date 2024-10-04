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

void	ft_init_ray(t_ray *ray, double plane_x)
{
	ray->perp_wall_dist = 0;
	ray->wall_x = 0;
	ray->wall_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->start = 0;
	ray->end = 0;
	ray->floor_begin = 0;
	ray->celling_begin = 0;
	ray->res = WEIGHT / plane_x;
	return ;
}

void	ft_init_player(t_program *data)
{
	data->game.player.plane_x = 320;
	data->game.player.position.x = data->start_x + 0.5;
	data->game.player.position.y = data->start_y + 0.5;
	data->game.player.fov = 60.0f;
	if (data->start == 'N')
		data->game.player.angle = 270;
	else if (data->start == 'S')
		data->game.player.angle = 90;
	else if (data->start == 'E')
		data->game.player.angle = 180;
	else if (data->start == 'W')
		data->game.player.angle = 0;
	data->game.player.speed_move = 200.0f;
	data->game.player.up = false;
	data->game.player.strafe_left = false;
	data->game.player.down = false;
	data->game.player.strafe_right = false;
	data->game.player.a = false;
	data->game.player.d = false;
	data->game.player.dir_x = 0;
	data->game.player.dir_y = 0;
	return ;
}

void	ft_second_init(t_program *data)
{
	data->game.bonus = data->bonus;
	data->game.c_color = data->c_colors;
	data->game.f_color = data->f_colors;
}

static void	ft_init_image(t_game *game)
{
	game->minimap.img = NULL;
	game->minimap.addr = NULL;
	game->img.img = NULL;
	game->img.addr = NULL;
}

int	ft_init_game(t_program *data)
{
	data->game.mlx = mlx_init();
	if (data->game.mlx == NULL)
		return (ft_serv_err(SERV_INIT, data));
	data->game.win = mlx_new_window(data->game.mlx, WEIGHT, HEIGHT, "Cub3d");
	if (data->game.win == NULL)
		return (ft_serv_err(WINDOW_ERR, data));
	ft_init_image(&data->game);
	data->game.minimap.img = mlx_new_image(data->game.mlx, 200, 200);
	if (data->game.minimap.img == NULL)
		return (ft_serv_err(MMAP_IMG, data));
	data->game.minimap.addr = (int *)mlx_get_data_addr(data->game.minimap.img,
			&data->game.minimap.bits_per_pixel, &data->game.minimap.line_length,
			&data->game.minimap.endian);
	if (data->game.minimap.addr == NULL)
		return (ft_serv_err(MMAP_ADDR, data));
	data->game.img.img = mlx_new_image(data->game.mlx, WEIGHT, HEIGHT);
	if (data->game.img.img == NULL)
		return (ft_serv_err(GAME_IMG, data));
	data->game.img.addr = (int *)mlx_get_data_addr(data->game.img.img,
			&data->game.img.bits_per_pixel, &data->game.img.line_length,
			&data->game.img.endian);
	if (data->game.img.addr == NULL)
		return (ft_serv_err(GAME_ADDR, data));
	data->game.old_x = WEIGHT / 2;
	return (EXIT_SUCCESS);
}
