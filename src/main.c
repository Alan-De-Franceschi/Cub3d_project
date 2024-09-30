/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:18:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/21 16:18:28 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_program	data;


	if (ft_parsing(argc, argv[1], &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_mouse_move(data.game.mlx, data.game.win, WEIGHT / 2, HEIGHT / 2);
	ft_first_raycast(&data.game);
	mlx_loop_hook(data.game.mlx, &ft_raycasting, &data.game);
	ft_event_handler(&data.game);
	mlx_loop(data.game.mlx);
	ft_free_parsing(&data);
	return (EXIT_SUCCESS);
}
