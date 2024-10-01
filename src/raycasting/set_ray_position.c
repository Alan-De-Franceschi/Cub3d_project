/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:31 by jaung             #+#    #+#             */
/*   Updated: 2024/06/15 16:00:32 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_set_ray_position(t_point *vec_ray, t_point *dir, t_player *player,
		int i)
{
	t_point	target;

	vec_ray->x = player->position.x;
	vec_ray->y = player->position.y;
	target.x = player->position.x + ft_cos((player->angle + player->fov / 2) - i
			* (player->fov / player->plane_x));
	target.y = player->position.y + ft_sin((player->angle + player->fov / 2) - i
			* (player->fov / player->plane_x));
	ft_normalize_vector(target.x - vec_ray->x, target.y - vec_ray->y, dir);
	return ;
}
