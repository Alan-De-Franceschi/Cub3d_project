/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:06:23 by jaung             #+#    #+#             */
/*   Updated: 2024/09/22 14:06:25 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_find_nearest_wall(t_ray *ray, t_game *game)
{
	while (1)
	{
		if (ray->interX < ray->interY)
		{
			game->map.x += ray->stepX;
			ray->interX += ray->UnitStep.x;
			ray->side = 0;
		}
		else
		{
			game->map.y += ray->stepY;
			ray->interY += ray->UnitStep.y;
			ray->side = 1;
		}
		if (game->map.map[game->map.y][game->map.x] == 1)
		{
			break ;
		}
	}
	return ;
}
