/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:41:03 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/27 12:41:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_parsing(int argc, char *argv, t_program *data)
{
	ft_init_data(data);
	if (ft_check_args(argv, argc, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_read_file(argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
