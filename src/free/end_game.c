/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:51:49 by jaung             #+#    #+#             */
/*   Updated: 2024/06/14 18:51:50 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <cub3d.h>

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_image(game->mlx, game->minimap.img);
	mlx_destroy_image(game->mlx, game->E.img);
	mlx_destroy_image(game->mlx, game->W.img);
	mlx_destroy_image(game->mlx, game->S.img);
	mlx_destroy_image(game->mlx, game->N.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
