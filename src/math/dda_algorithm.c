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
		if (ray->inter_x < ray->inter_y)
		{
			game->x += ray->step_x;
			ray->inter_x += ray->unit_step.x;
			ray->side = 0;
		}
		else
		{
			game->y += ray->step_y;
			ray->inter_y += ray->unit_step.y;
			ray->side = 1;
		}
		if (game->map[game->y][game->x] == '1')
		{
			break ;
		}
	}
	return ;
}
