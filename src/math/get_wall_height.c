/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:14:34 by jaung             #+#    #+#             */
/*   Updated: 2024/09/22 14:14:36 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->inter_x - ray->unit_step.x;
	else
		ray->perp_wall_dist = ray->inter_y - ray->unit_step.y;
}

void	ft_get_wall_info(t_ray *ray, t_game game, int i)
{
	double	ray_angle;

	ray_angle = game.player.angle - game.player.fov / 2 + (i
			/ game.player.plane_x) * game.player.fov;
	ft_get_perp_wall_dist(ray);
	ray->line_height = HEIGHT / (ray->perp_wall_dist * ft_cos(ray_angle
				- game.player.angle));
	ray->end = ray->line_height / 2 + HEIGHT / 2;
	ray->start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->end > HEIGHT || ray->end < 0)
	{
		ray->end = HEIGHT - 1;
	}
	if (ray->start < 0)
	{
		ray->start = 0;
	}
	ray->floor_begin = ray->end;
	ray->celling_begin = ray->start;
	return ;
}
