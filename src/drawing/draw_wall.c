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
	if (ray.dir.x < 0)
	{
		draw(&game->img, x + k, ray.start, game->e.addr[ray.i]);
	}
	else
	{
		draw(&game->img, x + k, ray.start, game->w.addr[ray.i]);
	}
}

static void	ft_draw_horizontal_wall(t_ray ray, t_game *game, int x, int k)
{
	if (ray.dir.y < 0)
	{
		draw(&game->img, x + k, ray.start, game->s.addr[ray.i]);
	}
	else
	{
		draw(&game->img, x + k, ray.start, game->n.addr[ray.i]);
	}
}

void	ft_draw_wall(t_ray ray, t_game *game, int x)
{
	int	k;

	ray.tex_x = (int)(ray.wall_x * (double)BLOC_SIZE);
	while (ray.start < ray.end)
	{
		ray.wall_y = (ray.start - HEIGHT / 2 + ray.line_height / 2) * 256;
		ray.tex_y = abs(((ray.wall_y * BLOC_SIZE) / ray.line_height) / 256);
		ray.i = ray.tex_y * (BLOC_SIZE) + ray.tex_x;
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
		ray.start++;
	}
	return ;
}
