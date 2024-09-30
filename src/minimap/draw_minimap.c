/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:09:58 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 16:09:59 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

static void	ft_check_for_map_limits(t_minimap *minimap, t_program data)
{
	if (minimap->start_x < 0)
	{
		minimap->end_x += abs(minimap->start_x);
		minimap->start_x = 0;
	}
	if (minimap->start_y < 0)
	{
		minimap->end_y += abs(minimap->start_y);
		minimap->start_y = 0;
	}
	if (minimap->end_x > data.nb_line)
	{
		minimap->start_x -= minimap->end_x - data.nb_line;
		if (minimap->start_x < 0)
			minimap->start_x = 0;
		minimap->end_x = data.nb_line;
	}
	if (minimap->end_y > data.nb_column)
	{
		minimap->start_y -= minimap->end_y - data.nb_column;
		if (minimap->start_y < 0)
			minimap->start_y = 0;
		minimap->end_y = data.nb_column;
	}
	return ;
}

static void	ft_init_minimap(t_minimap *minimap, t_program data)
{
	minimap->scale = 25;
	minimap->start_x = (int)data.game.player.position.x - 4;
	minimap->start_y = (int)data.game.player.position.y - 4;
	minimap->end_x = (int)data.game.player.position.x + 4;
	minimap->end_y = (int)data.game.player.position.y + 4;
	ft_check_for_map_limits(minimap, data);
	return ;
}

static void	ft_draw_minimap_wall(t_minimap minimap, t_data *img)
{
	int	k;
	int	i;

	k = 0;
	while (k < minimap.scale - 1)
	{
		i = 0;
		while (i < minimap.scale - 1)
		{
			draw(img, minimap.minimapX + i, minimap.minimapY + k, WHITE);
			i++;
		}
		k++;
	}
	return ;
}

static void	ft_draw_minimap_floor(t_minimap minimap, t_game *game, int x, int y)
{
	int	k;
	int	i;

	k = 0;
	while (k < minimap.scale - 1)
	{
		i = 0;
		while (i < minimap.scale - 1)
		{
			if (x == (int)game->player.position.x
				&& y == (int)game->player.position.y)
			{
				draw(&game->minimap, minimap.minimapX + i, minimap.minimapY + k,
					GREEN);
			}
			else
			{
				draw(&game->minimap, minimap.minimapX + i, minimap.minimapY + k,
					GREY);
			}
			i++;
		}
		k++;
	}
	return ;
}

void	ft_draw_minimap(t_program *data)
{
	t_minimap	minimap;
	int			y;
	int			x;

	ft_init_minimap(&minimap, *data);
	y = minimap.start_y;
	while (y < minimap.end_y)
	{
		x = minimap.start_x;
		while (x < minimap.end_x)
		{
			minimap.minimapX = minimap.scale * (x - minimap.start_x);
			minimap.minimapY = minimap.scale * (y - minimap.start_y);
			if (data->game.map[y][x])
			{
				ft_draw_minimap_wall(minimap, &data->game.minimap);
			}
			else
			{
				ft_draw_minimap_floor(minimap, &data->game, x, y);
			}
			x++;
		}
		y++;
	}
}
