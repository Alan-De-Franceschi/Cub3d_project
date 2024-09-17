/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:51:10 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/27 12:51:12 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_parsing_err(int err, t_program *data)
{
	if (err == FILE_ERR)
		ft_putstr_fd("Error\nArgs: Invalid filename\n", 2);
	else if (err == FEW_ARGS)
		ft_putstr_fd("Error\nArgs: Too few arguments\n", 2);
	else if (err == MANY_ARGS)
		ft_putstr_fd("Error\nArgs: Too many arguments\n", 2);
	else if (err == OPEN_ERR)
		perror("Error\nOpen");
	else if (err == GNL_ERR)
		ft_putstr_fd("Error\nGet Next Line: Error\n", 2);
	else if (err == W_PARAM)
		ft_putstr_fd("Error\nParsing: Wrong parameters format\n", 2);
	else if (err == SPLIT_MEM)
		perror("Error\nSplit\n");
	else if (err == MEM_ERR)
		perror("Error\nMalloc\n");
	else if (err == PATH_ERR)
		perror("Open");
	else if (err == ATOI_ERR)
		ft_putstr_fd("Error\nAtoi: numeric argument (range[0,255]) required\n",
			2);
	ft_free_parsing(data);
	return (EXIT_FAILURE);
}
