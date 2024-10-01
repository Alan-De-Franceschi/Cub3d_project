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

t_point	ft_get_distance_for_next_intersection(t_point dir)
{
	t_point	unit_step;

	unit_step.x = sqrt(1 + (dir.y / dir.x) * (dir.y / dir.x));
	unit_step.y = sqrt(1 + (dir.x / dir.y) * (dir.x / dir.y));
	return (unit_step);
}

void	ft_get_first_intersection_coordinates(t_ray *ray, t_game *game)
{
	game->x = (int)ray->vec_ray.x;
	game->y = (int)ray->vec_ray.y;
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->inter_x = (ray->vec_ray.x - game->x) * ray->unit_step.x;
	}
	else
	{
		ray->step_x = 1;
		ray->inter_x = (game->x + 1 - ray->vec_ray.x) * ray->unit_step.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->inter_y = (ray->vec_ray.y - game->y) * ray->unit_step.y;
	}
	else
	{
		ray->step_y = 1;
		ray->inter_y = (game->y + 1 - ray->vec_ray.y) * ray->unit_step.y;
	}
	return ;
}
