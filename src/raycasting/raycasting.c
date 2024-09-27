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
		ray->wallX = ray->vecRay.y + ray->perpWallDist * ray->direction.y;
	}
	else
	{
		ray->wallX = ray->vecRay.x + ray->perpWallDist * ray->direction.x;
	}
	ray->wallX = ray->wallX - (int)ray->wallX;
	return ;
}

int	ft_raycasting(t_game *game)
{
	game->begin = ft_get_current_time();
	ft_clear_image(game->img.addr, WEIGHT, HEIGHT);
	ft_raycast(game);
	if (BONUS)
	{
		ft_clear_image(game->minimap.addr, 200, 200);
		ft_minimap(game);
	}
	return (0);
}

void	ft_first_raycast(t_game *game)
{
	t_ray	ray;
	int		x;
	int		i;

	i = 0;
	x = WEIGHT;
	ft_init_ray(&ray, (*game).player.planeX);
	while (i < game->player.planeX)
	{
		ft_set_ray_position(&ray.vecRay, &ray.direction, &game->player, i);
		ft_get_player_dir(game);
		ray.UnitStep = ft_get_distance_for_next_intersection(ray.direction);
		ft_get_first_intersection_coordinates(&ray, game);
		ft_find_nearest_wall(&ray, game);
		ft_get_x_point_of_impact(&ray);
		ft_get_wall_info(&ray, *game, i);
		x -= WEIGHT / game->player.planeX;
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
	x = WEIGHT;
	ft_init_ray(&ray, (*game).player.planeX);
	if (ft_update_player_position(game))
	{
		while (i < game->player.planeX)
		{
			ft_set_ray_position(&ray.vecRay, &ray.direction, &game->player, i);
			ft_get_player_dir(game);
			ray.UnitStep = ft_get_distance_for_next_intersection(ray.direction);
			ft_get_first_intersection_coordinates(&ray, game);
			ft_find_nearest_wall(&ray, game);
			ft_get_x_point_of_impact(&ray);
			ft_get_wall_info(&ray, *game, i);
			x -= WEIGHT / game->player.planeX;
			ft_draw_player_viewpoint(ray, game, x);
			i++;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (0);
}
