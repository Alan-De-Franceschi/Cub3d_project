/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:30:10 by jaung             #+#    #+#             */
/*   Updated: 2024/09/26 16:30:10 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_event_handler(t_program *data)
{
	mlx_hook(data->game.win, KeyPress, KeyPressMask, &ft_on_key_press, data);
	mlx_hook(data->game.win, KeyRelease, KeyReleaseMask, &ft_on_key_release,
		&data->game.player);
	mlx_hook(data->game.win, DestroyNotify, StructureNotifyMask, &end_game,
		data);
	if (data->bonus == 1)
		mlx_hook(data->game.win, LeaveNotify, LeaveWindowMask, &ft_manage_mouse,
			&data->game);
	return ;
}
