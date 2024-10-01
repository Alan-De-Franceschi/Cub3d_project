/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:04:53 by jaung             #+#    #+#             */
/*   Updated: 2024/09/24 11:04:54 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_move_up(char **map, t_player *player, double delta_time)
{
	float	new_x;
	float	new_y;

	if (delta_time != 0)
	{
		new_x = player->position.x + ft_cos(player->angle) * MOVE_SPEED
			* delta_time;
		new_y = player->position.y + ft_sin(player->angle) * MOVE_SPEED
			* delta_time;
	}
	else
	{
		new_x = player->position.x + ft_cos(player->angle) * MOVE_SPEED;
		new_y = player->position.y + ft_sin(player->angle) * MOVE_SPEED;
	}
	if (map[(int)(new_y + 0.3 * player->dir_y)][(int)player->position.x] != '1')
	{
		player->position.y = new_y;
	}
	if (map[(int)player->position.y][(int)(new_x + 0.3 * player->dir_x)] != '1')
	{
		player->position.x = new_x;
	}
}

void	ft_move_down(char **map, t_player *player, double delta_time)
{
	float	new_x;
	float	new_y;

	if (delta_time != 0)
	{
		new_x = player->position.x - ft_cos(player->angle) * MOVE_SPEED
			* delta_time;
		new_y = player->position.y - ft_sin(player->angle) * MOVE_SPEED
			* delta_time;
	}
	else
	{
		new_x = player->position.x - ft_cos(player->angle) * MOVE_SPEED;
		new_y = player->position.y - ft_sin(player->angle) * MOVE_SPEED;
	}
	if (map[(int)(new_y - 0.3 * player->dir_y)][(int)player->position.x] != '1')
	{
		player->position.y = new_y;
	}
	if (map[(int)player->position.y][(int)(new_x - 0.3 * player->dir_x)] != '1')
	{
		player->position.x = new_x;
	}
}

void	ft_move_left(char **map, t_player *player, double delta_time)
{
	float	new_x;
	float	new_y;
	float	strafe_x;
	float	strafe_y;

	strafe_x = ft_sin(player->angle);
	strafe_y = -ft_cos(player->angle);
	if (delta_time != 0)
	{
		new_x = player->position.x + strafe_x * MOVE_SPEED * delta_time;
		new_y = player->position.y + strafe_y * MOVE_SPEED * delta_time;
	}
	else
	{
		new_x = player->position.x + strafe_x * MOVE_SPEED;
		new_y = player->position.y + strafe_y * MOVE_SPEED;
	}
	if (map[(int)(new_y + 0.3 * strafe_y)][(int)player->position.x] != '1')
	{
		player->position.y = new_y;
	}
	if (map[(int)player->position.y][(int)(new_x + 0.3 * strafe_x)] != '1')
	{
		player->position.x = new_x;
	}
}

void	ft_move_right(char **map, t_player *player, double delta_time)
{
	float	new_x;
	float	new_y;
	float	strafe_x;
	float	strafe_y;

	strafe_x = -ft_sin(player->angle);
	strafe_y = ft_cos(player->angle);
	if (delta_time != 0)
	{
		new_x = player->position.x + strafe_x * MOVE_SPEED * delta_time;
		new_y = player->position.y + strafe_y * MOVE_SPEED * delta_time;
	}
	else
	{
		new_x = player->position.x + strafe_x * MOVE_SPEED;
		new_y = player->position.y + strafe_y * MOVE_SPEED;
	}
	if (map[(int)(new_y + 0.3 * strafe_y)][(int)player->position.x] != '1')
	{
		player->position.y = new_y;
	}
	if (map[(int)player->position.y][(int)(new_x + 0.3 * strafe_x)] != '1')
	{
		player->position.x = new_x;
	}
}
