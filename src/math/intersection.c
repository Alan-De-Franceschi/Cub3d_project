/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:03:04 by jaung             #+#    #+#             */
/*   Updated: 2024/09/22 14:03:05 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

t_point	ft_get_distance_for_next_intersection(t_point direction)
{
	t_point	unit_step;

	unit_step.x = sqrt(1 + (direction.y / direction.x) * (direction.y
				/ direction.x));
	unit_step.y = sqrt(1 + (direction.x / direction.y) * (direction.x
				/ direction.y));
	return (unit_step);
}

void	ft_get_first_intersection_coordinates(t_ray *ray, t_game *game)
{
	game->map->x = (int)ray->vecRay.x;
	game->map->y = (int)ray->vecRay.y;
	if (ray->direction.x < 0)
	{
		ray->stepX = -1;
		ray->interX = (ray->vecRay.x - game->map->x) * ray->UnitStep.x;
	}
	else
	{
		ray->stepX = 1;
		ray->interX = (game->map->x + 1 - ray->vecRay.x) * ray->UnitStep.x;
	}
	if (ray->direction.y < 0)
	{
		ray->stepY = -1;
		ray->interY = (ray->vecRay.y - game->map->y) * ray->UnitStep.y;
	}
	else
	{
		ray->stepY = 1;
		ray->interY = (game->map->y + 1 - ray->vecRay.y) * ray->UnitStep.y;
	}
	return ;
}
