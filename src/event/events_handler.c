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

void	ft_event_handler(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &ft_on_key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &ft_on_key_release,
		&game->player);
	mlx_hook(game->win, LeaveNotify, LeaveWindowMask, &ft_manage_mouse, game);
	return ;
}
