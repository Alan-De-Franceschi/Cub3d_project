/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_celling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:03:14 by jaung             #+#    #+#             */
/*   Updated: 2024/09/26 17:03:15 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_draw_floor_and_celling(t_ray ray, t_game *game, int x)
{
	int	k;

	while (ray.floorBegin < HEIGHT)
	{
		k = 0;
		while (k < ray.res)
		{
			draw(&game->img, x + k, ray.floorBegin, WHITE);
			k++;
		}
		ray.floorBegin++;
	}
	while (ray.cellingBegin > 0)
	{
		k = 0;
		while (k < ray.res)
		{
			draw(&game->img, x + k, ray.cellingBegin, BLUE);
			k++;
		}
		ray.cellingBegin--;
	}
	return ;
}
