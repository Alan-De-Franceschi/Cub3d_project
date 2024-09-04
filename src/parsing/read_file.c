/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:31:18 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/30 15:31:20 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_read_param(char *line, t_program *data)
{
	while (*line == ' ')
		line++;
	if (*line == '\n')
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "NO", 2) == 0)
		return(ft_save_path(line, data->n_path, data->parameters));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return(ft_save_path(line, data->s_path, data->parameters));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return(ft_save_path(line, data->w_path, data->parameters));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return(ft_save_path(line, data->e_path, data->parameters));
	else if (ft_strncmp(line, "F", 1) == 0)
		return(ft_save_colors(line, data->f_colors, data->parameters));
	else if (ft_strncmp(line, "C", 1) == 0)
		return(ft_save_colors(line, data->c_colors, data->parameters));
	else
		return (ft_parsing_err(W_PARAM, data));
	return (EXIT_SUCCESS);
}

int	ft_read_file(char *argv, t_program *data)
{
	char *line;

	data->map_file = open(argv, O_RDONLY);
	if (data->map_file == -1)
		return (ft_parsing_err(OPEN_ERR, data));
	while (1)
	{
		line = ft_get_next_line(data->map_file, data->err);
		if (!line)
		{
			if (data->err || errno)
				return (ft_parsing_err(GNL_ERR, data));
			else
				return (EXIT_SUCCESS);
		}
		if (data->parameters < 6)
		{
			if (ft_read_param(line, data) == EXIT_FAILURE)
				return (free(line), EXIT_FAILURE);
		}
		free(line);
	}
}

