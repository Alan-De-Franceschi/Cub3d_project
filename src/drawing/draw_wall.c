/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:21:14 by jaung             #+#    #+#             */
/*   Updated: 2024/09/24 11:21:15 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_draw_vertical_wall(t_ray ray, t_game *game, int x, int k)
{
	if (ray.direction.x < 0)
	{
		draw(&game->img, x + k, ray.Start, game->E.addr[ray.i]);
	}
	else
	{
		draw(&game->img, x + k, ray.Start, game->W.addr[ray.i]);
	}
}

static void	ft_draw_horizontal_wall(t_ray ray, t_game *game, int x, int k)
{
	if (ray.direction.y < 0)
	{
		draw(&game->img, x + k, ray.Start, game->S.addr[ray.i]);
	}
	else
	{
		draw(&game->img, x + k, ray.Start, game->N.addr[ray.i]);
	}
}

void	ft_draw_wall(t_ray ray, t_game *game, int x)
{
	int	k;

	ray.tex_x = (int)(ray.wallX * (double)BLOC_SIZE);
	while (ray.Start < ray.End)
	{
		ray.d = (ray.Start - HEIGHT / 2 + ray.lineHeight / 2) * 128;
		ray.tex_y = ((ray.d * BLOC_SIZE) / ray.lineHeight) / 128;
		ray.i = ray.tex_y * (game->E.line_length / 4) + ray.tex_x;
		k = 0;
		while (k < ray.res)
		{
			if (ray.side == 0)
			{
				ft_draw_vertical_wall(ray, game, x, k);
			}
			else if (ray.side == 1)
			{
				ft_draw_horizontal_wall(ray, game, x, k);
			}
			k++;
		}
		ray.Start++;
	}
	return ;
}
