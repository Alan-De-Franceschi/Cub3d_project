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

	if (ft_parsing(argc, argv[1], &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_free_parsing(&data);
	return (EXIT_SUCCESS);
}
