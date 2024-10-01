/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:38:10 by jaung             #+#    #+#             */
/*   Updated: 2024/06/15 11:38:11 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_rotate_left(t_player *player, double delta_time)
{
	if (delta_time != 0)
	{
		player->angle -= player->speed_move * ANGLE_SPEED * delta_time;
	}
	else
	{
		player->angle -= player->speed_move * ANGLE_SPEED;
	}
	if (player->angle < 0)
	{
		player->angle = 360;
	}
	return ;
}

static void	ft_rotate_right(t_player *player, double delta_time)
{
	if (delta_time != 0)
	{
		player->angle += player->speed_move * ANGLE_SPEED * delta_time;
	}
	else
	{
		player->angle += player->speed_move * ANGLE_SPEED;
	}
	if (player->angle > 360)
	{
		player->angle = 0;
	}
	return ;
}

static void	ft_move_player(t_game *game, double delta_time)
{
	if (game->player.up == true)
	{
		ft_move_up(game->map, &game->player, delta_time);
	}
	if (game->player.down == true)
	{
		ft_move_down(game->map, &game->player, delta_time);
	}
	if (game->player.a == true)
	{
		ft_move_left(game->map, &game->player, delta_time);
	}
	if (game->player.d == true)
	{
		ft_move_right(game->map, &game->player, delta_time);
	}
	if (game->player.strafe_left == true)
	{
		ft_rotate_left(&game->player, delta_time);
	}
	if (game->player.strafe_right == true)
	{
		ft_rotate_right(&game->player, delta_time);
	}
	return ;
}

int	ft_update_player_position(t_game *game)
{
	double	delta_time;
	double	old_x;
	double	old_y;
	float	old_angle;

	old_x = game->player.position.x;
	old_y = game->player.position.y;
	old_angle = game->player.angle;
	game->end = ft_get_current_time();
	delta_time = ft_get_time_in_millisecond(&game->end)
		- ft_get_time_in_millisecond(&game->begin);
	ft_move_player(game, delta_time);
	if (game->bonus == 1)
	{
		ft_mouse_move(game);
	}
	if (old_x != game->player.position.x || old_y != game->player.position.y
		|| old_angle != game->player.angle)
	{
		return (mlx_clear_window(game->mlx, game->win), 1);
	}
	return (0);
}
