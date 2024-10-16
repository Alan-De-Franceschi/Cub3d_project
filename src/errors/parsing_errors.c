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

#include "cub3d.h"

static void	ft_print_wrong_param(int err, char *param)
{
	if (err == DUP_PARAM)
	{
		ft_printf("Error\n", 2);
		write(2, param, ft_strlen(param) - 1);
		ft_printf(": Duplicate parameter\n", 2);
	}
	else if (err == W_PARAM)
	{
		ft_printf("Error\n", 2);
		write(2, param, ft_strlen(param) - 1);
		ft_printf(": Wrong parameter format\n", 2);
	}
}

int	ft_parsing_err(int err, char *param, t_program *data)
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
		ft_print_wrong_param(err, param);
	else if (err == DUP_PARAM)
		ft_print_wrong_param(err, param);
	else if (err == MEM_ERR || err == SPLIT_MEM)
		perror("Error\nMalloc");
	else if (err == PATH_ERR)
		perror("Open");
	else if (err == ATOI_ERR)
		ft_putstr_fd("Error\nAtoi: numeric argument (range[0,255]) required\n",
			2);
	ft_free_parsing(data);
	return (EXIT_FAILURE);
}

int	ft_map_err(int err, int start, int line, char c)
{
	if (err == INV_CHAR)
	{
		if (c == 9)
			ft_printf("Error\nMap: Tab on line %d\n", 2, line);
		else
			ft_printf("Error\nMap: Invalid char '%c' on line %d\n", 2, c, line);
	}
	else if (err == NOT_CLOSED)
		ft_printf("Error\nMap: Map not closed at line %d\n", 2, line);
	else if (err == MAP_SIZE)
		ft_printf("Error\nMap: Map size less than 3 lines\n", 2);
	else if (err == NO_START)
	{
		if (start < 1)
			ft_printf("Error\nMap : There is no start point\n", 2);
		else
			ft_printf("Error\nMap : There is more than one start point\n", 2);
	}
	else if (err == EMPTY_LINE)
		ft_putstr_fd("Error\nEmpty line on map\n", 2);
	return (EXIT_FAILURE);
}

int	ft_assets_err(int err, char *path, t_program *data)
{
	if (err == LOAD_ASSET)
		ft_printf("Error\n%s: Impossible to load asset image\n", 2, path);
	else if (err == ASSET_ADDR)
		ft_printf("Error\n%s: Impossible to save image address\n", 2, path);
	ft_free_parsing(data);
	return (EXIT_FAILURE);
}
