/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:59 by jaung             #+#    #+#             */
/*   Updated: 2024/09/23 14:33:01 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_get_x_point_of_impact(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->wall_x = ray->vec_ray.y + ray->perp_wall_dist * ray->dir.y;
	}
	else
	{
		ray->wall_x = ray->vec_ray.x + ray->perp_wall_dist * ray->dir.x;
	}
	ray->wall_x = ray->wall_x - (int)ray->wall_x;
	return ;
}

int	ft_raycasting(t_program *data)
{
	data->game.begin = ft_get_current_time();
	ft_clear_image(data->game.img.addr, WEIGHT, HEIGHT);
	ft_raycast(&data->game);
	if (data->bonus == 1)
	{
		ft_clear_image(data->game.minimap.addr, 200, 200);
		ft_minimap(data);
	}
	return (0);
}

void	ft_first_raycast(t_game *game)
{
	t_ray	ray;
	int		x;
	int		i;

	i = 0;
	x = 0;
	ft_init_ray(&ray, (*game).player.plane_x);
	while (i < game->player.plane_x)
	{
		ft_set_ray_position(&ray.vec_ray, &ray.dir, &game->player, i);
		ft_get_player_dir(game);
		ray.unit_step = ft_get_distance_for_next_intersection(ray.dir);
		ft_get_first_intersection_coordinates(&ray, game);
		ft_find_nearest_wall(&ray, game);
		ft_get_x_point_of_impact(&ray);
		ft_get_wall_info(&ray, *game, i);
		x -= WEIGHT / game->player.plane_x;
		ft_draw_player_viewpoint(ray, game, x);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return ;
}

int	ft_raycast(t_game *game)
{
	t_ray	ray;
	int		x;
	int		i;

	i = 0;
	x = 0;
	ft_init_ray(&ray, game->player.plane_x);
	if (ft_update_player_position(game))
	{
		while (i < game->player.plane_x)
		{
			ft_set_ray_position(&ray.vec_ray, &ray.dir, &game->player, i);
			ft_get_player_dir(game);
			ray.unit_step = ft_get_distance_for_next_intersection(ray.dir);
			ft_get_first_intersection_coordinates(&ray, game);
			ft_find_nearest_wall(&ray, game);
			ft_get_x_point_of_impact(&ray);
			ft_get_wall_info(&ray, *game, i);
			x -= WEIGHT / game->player.plane_x;
			ft_draw_player_viewpoint(ray, game, x);
			i++;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (0);
}
