/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:24:32 by jaung             #+#    #+#             */
/*   Updated: 2024/09/23 14:24:34 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_minimap(t_game *game)
{
	ft_draw_minimap(&game->map, game);
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img, 0, 0);
	return ;
}
