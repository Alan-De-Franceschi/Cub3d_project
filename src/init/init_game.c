/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:37:13 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 13:37:15 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	return ;
}

void	ft_init_ray(t_ray *ray, double planeX)
{
	ray->perpWallDist = 0;
	ray->wallX = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->lineHeight = 0;
	ray->Start = 0;
	ray->End = 0;
	ray->floorBegin = 0;
	ray->cellingBegin = 0;
	ray->res = WEIGHT / planeX;
	return ;
}

static void	ft_init_player(t_player *player)
{
	player->planeX = 320;
	player->position.x = 2.1;
	player->position.y = 4.1;
	player->fov = 60.0f;
	player->angle = 270.0f;
	player->speedMove = 200.0f;
	player->up = false;
	player->strafe_left = false;
	player->down = false;
	player->strafe_right = false;
	player->a = false;
	player->d = false;
	player->dir_x = 0;
	player->dir_y = 0;
	return ;
}

int	ft_init_game(t_game *game)
{
	int	weight;
	int	height;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (1);
	game->win = mlx_new_window(game->mlx, WEIGHT, HEIGHT, "Cub3d");
	if (game->win == NULL)
		return (free(game->mlx), 1);
	ft_init_map(&game->map);
	ft_init_player(&game->player);
	game->minimap.img = mlx_new_image(game->mlx, 200, 200);
	if (game->minimap.img == NULL)
		return (free(game->mlx), free(game->win), 1);
	game->minimap.addr = (int *)mlx_get_data_addr(game->minimap.img,
			&game->minimap.bits_per_pixel, &game->minimap.line_length,
			&game->minimap.endian);
	game->img.img = mlx_new_image(game->mlx, WEIGHT, HEIGHT);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	game->E.img = NULL;
	game->E.img = mlx_xpm_file_to_image(game->mlx, "assets/Bricks_1.xpm",
			&weight, &height);
	game->E.addr = (int *)mlx_get_data_addr(game->E.img,
			&game->E.bits_per_pixel, &game->E.line_length, &game->E.endian);
	game->W.img = mlx_xpm_file_to_image(game->mlx, "assets/Star-Block_1.xpm",
			&weight, &height);
	game->W.addr = (int *)mlx_get_data_addr(game->W.img,
			&game->W.bits_per_pixel, &game->W.line_length, &game->W.endian);
	game->S.img = mlx_xpm_file_to_image(game->mlx,
			"assets/Mossy-Small-Brick_1.xpm", &weight, &height);
	game->S.addr = (int *)mlx_get_data_addr(game->S.img,
			&game->S.bits_per_pixel, &game->S.line_length, &game->S.endian);
	game->N.img = mlx_xpm_file_to_image(game->mlx, "assets/Wood.xpm", &weight,
			&height);
	game->N.addr = (int *)mlx_get_data_addr(game->N.img,
			&game->N.bits_per_pixel, &game->N.line_length, &game->N.endian);
	game->oldX = WEIGHT / 2;
	return (0);
}
