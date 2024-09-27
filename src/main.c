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

// static void	ft_print_parsing(t_program *data)
// {
// 	int	i;
// 	int	step;

// 	i = 0;
// 	step = 0;
// 	ft_printf("North = %s\n", 1, data->n_path);
// 	ft_printf("South = %s\n", 1, data->s_path);
// 	ft_printf("West = %s\n", 1, data->w_path);
// 	ft_printf("East = %s\n", 1, data->e_path);
// 	ft_printf("\nF_colors :\n%x\n", 1, data->f_colors);
// 	ft_printf("\nC_colors :\n%x\n", 1, data->c_colors);
// 	i = 0;
// 	ft_printf("\nVector array :\n", 1);
// 	while (data->vemap->array[i])
// 	{
// 		ft_printf("%s", 1, data->vemap->array[i]);
// 		++i;
// 	}
// 	i = 0;
// 	ft_printf("\n\nMap :\n", 1);
// 	while (i < 462)
// 	{
// 		if (data->map[i].y > step)
// 		{
// 			ft_printf("\n", 1);
// 			step = data->map[i].y;
// 		}
// 		ft_printf("%c", 1, data->map[i].value);
// 		++i;
// 	}
// 	printf("\n");
// 	printf("\nStart:\n");
// 	printf("x = %d\n", data->start_x);
// 	printf("y = %d\n", data->start_y);
// 	printf("value = %c\n\n", data->start);
// }

int	main(int argc, char **argv)
{
	t_program	data;


	if (ft_parsing(argc, argv[1], &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_mouse_move(game.mlx, game.win, WEIGHT / 2, HEIGHT / 2);
	ft_first_raycast(&game);
	mlx_loop_hook(game.mlx, &ft_raycasting, &game);
	ft_event_handler(&game);
	mlx_loop(game.mlx);
	// ft_print_parsing(&data);
	ft_free_parsing(&data);
	return (EXIT_SUCCESS);
}
