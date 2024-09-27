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

void	ft_set_ray_position(t_point *vecRay, t_point *direction,
		t_player *player, int i)
{
	t_point	target;

	vecRay->x = player->position.x;
	vecRay->y = player->position.y;
	target.x = player->position.x + ft_cos((player->angle + player->fov / 2) - i
			* (player->fov / player->planeX));
	target.y = player->position.y + ft_sin((player->angle + player->fov / 2) - i
			* (player->fov / player->planeX));
	ft_normalize_vector(target.x - vecRay->x, target.y - vecRay->y, direction);
	return ;
}
