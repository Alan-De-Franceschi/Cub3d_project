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

#include "cube.h"

int	main(int argc, char **argv)
{
	t_program	data;
	int			i;

	i = 0;
	if (ft_parsing(argc, argv[1], &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_printf("North = %s\n", 1, data.n_path);
	ft_printf("South = %s\n", 1, data.s_path);
	ft_printf("West = %s\n", 1, data.w_path);
	ft_printf("East = %s\n", 1, data.e_path);
	ft_printf("\nF_colors :\n", 1);
	while (i < 3)
	{
		ft_printf("%d\n", 1, data.f_colors[i]);
		++i;
	}
	i = 0;
	ft_printf("\nC_colors :\n", 1);
	while (i < 3)
	{
		ft_printf("%d\n", 1, data.c_colors[i]);
		++i;
	}
	i = 0;
	ft_printf("\nMap array :\n", 1);
	while (data.vemap->array[i])
	{
		ft_printf("%s", 1, data.vemap->array[i]);
		++i;
	}
	ft_free_parsing(&data);
	return (EXIT_SUCCESS);
}