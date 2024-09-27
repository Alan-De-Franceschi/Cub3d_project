/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_viewpoint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:01:13 by jaung             #+#    #+#             */
/*   Updated: 2024/09/26 17:01:14 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_draw_player_viewpoint(t_ray ray, t_game *game, int x)
{
	ft_draw_wall(ray, game, x);
	ft_draw_floor_and_celling(ray, game, x);
	return ;
}
