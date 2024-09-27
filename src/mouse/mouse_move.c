/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:51:52 by jaung             #+#    #+#             */
/*   Updated: 2024/09/24 16:51:53 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_manage_mouse(t_game *game)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	if (x < 0 && y < 0)
		mlx_mouse_move(game->mlx, game->win, 0, 0);
	else if (x >= WEIGHT && y <= 0)
		mlx_mouse_move(game->mlx, game->win, WEIGHT / 2, HEIGHT / 2);
	else if (x == 0 && y < HEIGHT)
		mlx_mouse_move(game->mlx, game->win, WEIGHT / 2, HEIGHT / 2);
	else if (x > WEIGHT && y > HEIGHT)
		mlx_mouse_move(game->mlx, game->win, WEIGHT / 2, HEIGHT / 2);
	else if (x <= 0 && y > HEIGHT)
		mlx_mouse_move(game->mlx, game->win, WEIGHT / 2, HEIGHT / 2);
	else if (x <= 0)
		mlx_mouse_move(game->mlx, game->win, 1, y);
	else if (x >= WEIGHT)
		mlx_mouse_move(game->mlx, game->win, WEIGHT - 1, y);
	else if (y <= 0)
		mlx_mouse_move(game->mlx, game->win, x, 1);
	else if (y >= HEIGHT)
		mlx_mouse_move(game->mlx, game->win, x, HEIGHT - 1);
	return (0);
}

int	ft_mouse_move(t_game *game)
{
	int		x;
	int		y;
	float	delta_x;

	mlx_mouse_get_pos(game->mlx, game->win, &x, &y);
	if (game->oldX >= WEIGHT - 1 || x >= WEIGHT - 1)
		delta_x = 2;
	else if (game->oldX <= 1 || x <= 1)
		delta_x = -2;
	else
		delta_x = x - game->oldX;
	if (x != game->oldX)
		game->oldX = x;
	game->player.angle += delta_x * 0.15;
	if (game->player.angle < 0)
		game->player.angle = 360;
	if (game->player.angle > 360)
		game->player.angle = 0;
	return (0);
}
