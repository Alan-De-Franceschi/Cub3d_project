/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:44:51 by jaung             #+#    #+#             */
/*   Updated: 2024/06/15 11:44:51 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	ft_on_key_release(int keycode, t_player *player)
{
	if (keycode == XK_w)
		player->up = false;
	if (keycode == XK_Left)
		player->strafe_left = false;
	if (keycode == XK_s)
		player->down = false;
	if (keycode == XK_Right)
		player->strafe_right = false;
	if (keycode == XK_a)
		player->a = false;
	if (keycode == XK_d)
		player->d = false;
	return (0);
}
