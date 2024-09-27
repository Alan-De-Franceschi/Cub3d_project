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
		ray->perpWallDist = ray->interX - ray->UnitStep.x;
	else
		ray->perpWallDist = ray->interY - ray->UnitStep.y;
}

void	ft_get_wall_info(t_ray *ray, t_game game, int i)
{
	double	ray_angle;

	ray_angle = game.player.angle - game.player.fov / 2 + (i
			/ game.player.planeX) * game.player.fov;
	ft_get_perp_wall_dist(ray);
	ray->lineHeight = HEIGHT / (ray->perpWallDist * ft_cos(ray_angle
				- game.player.angle));
	ray->End = ray->lineHeight / 2 + HEIGHT / 2;
	ray->Start = -ray->lineHeight / 2 + HEIGHT / 2;
	if (ray->End > HEIGHT || ray->End < 0)
	{
		ray->End = HEIGHT - 1;
	}
	if (ray->Start < 0)
	{
		ray->Start = 0;
	}
	ray->floorBegin = ray->End;
	ray->cellingBegin = ray->Start;
	return ;
}
