/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:33:47 by jaung             #+#    #+#             */
/*   Updated: 2024/09/25 09:33:48 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static void	ft_get_player_dir2(t_game *game)
{
	if (game->player.angle > 0 && game->player.angle < 90)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 1;
	}
	else if (game->player.angle > 90 && game->player.angle < 180)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 1;
	}
	else if (game->player.angle > 180 && game->player.angle < 270)
	{
		game->player.dir_x = -1;
		game->player.dir_y = -1;
	}
	else if (game->player.angle > 270 && game->player.angle < 360)
	{
		game->player.dir_x = 1;
		game->player.dir_y = -1;
	}
	return ;
}

void	ft_get_player_dir(t_game *game)
{
	if (game->player.angle == 0 || game->player.angle == 360)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (game->player.angle == 90)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->player.angle == 180)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->player.angle == 270)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	ft_get_player_dir2(game);
	return ;
}
