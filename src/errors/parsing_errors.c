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
		ft_putstr_fd("Error\nArgs: Invalid filename", 2);
	else if (err == FEW_ARGS)
		ft_putstr_fd("Error\nArgs: Too few arguments", 2);
	else if (err == MANY_ARGS)
		ft_putstr_fd("Error\nArgs: Too many arguments", 2);
	else if (err == OPEN_ERR)
		perror("Error\nOpen");
	else if (err == GNL_ERR)
		ft_putstr_fd("Error\nGet Next Line: Error", 2);
	else if (err == W_PARAM)
		ft_putstr_fd("Error\nParsing: Wrong parameters format", 2);
	else if (err == SPLIT_MEM)
		perror("Error\nSplit");
	else if (err == MEM_ERR)
		perror("Error\nMalloc");
	else if (err == PATH_ERR)
		perror("Open");
	ft_free_parsing(data);
	return (EXIT_FAILURE);
}
