/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:04:12 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 19:04:14 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_on_key_press(int keycode, t_program *data)
{
	if (keycode == XK_Escape)
		end_game(data);
	if (keycode == XK_w)
		game->player.up = true;
	if (keycode == XK_Left)
		game->player.strafe_left = true;
	if (keycode == XK_s)
		game->player.down = true;
	if (keycode == XK_Right)
		game->player.strafe_right = true;
	if (keycode == XK_a)
		game->player.a = true;
	if (keycode == XK_d)
		game->player.d = true;
	return (0);
}
