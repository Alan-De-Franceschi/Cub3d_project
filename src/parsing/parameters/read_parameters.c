/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:45:44 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 17:45:45 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_read_param(char *line, t_program *data)
{
	while (*line == ' ' || *line == 9)
		line++;
	if (*line == '\n')
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (ft_save_path(line, &data->game.n, data, &data->n));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (ft_save_path(line, &data->game.s, data, &data->s));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (ft_save_path(line, &data->game.w, data, &data->w));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (ft_save_path(line, &data->game.e, data, &data->e));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (ft_save_colors(line, &data->f_colors, data, &data->f));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (ft_save_colors(line, &data->c_colors, data, &data->c));
	else
		return (ft_parsing_err(W_PARAM, line, data));
	return (EXIT_SUCCESS);
}
