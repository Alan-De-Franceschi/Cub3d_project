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

#include "cub3d.h"

static int	ft_read_file(t_program *data)
{
	char	*line;

	while (1)
	{
		line = ft_get_next_line(data->map_file, &data->err);
		if (!line)
		{
			if (data->err || errno)
				return (ft_parsing_err(GNL_ERR, NULL, data));
			return (EXIT_SUCCESS);
		}
		if (data->parameters < 6)
		{
			if (ft_read_param(line, data) == EXIT_FAILURE)
				return (free(line), EXIT_FAILURE);
			free(line);
		}
		else
		{
			if (ft_read_map(line, data->vemap, data) == EXIT_FAILURE)
				return (free(line), EXIT_FAILURE);
			line = NULL;
		}
	}
}

int	ft_parsing(int argc, char *argv, t_program *data)
{
	if (ft_init_data(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_args(argv, argc, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->map_file = open(argv, O_RDONLY);
	if (data->map_file == -1)
		return (ft_parsing_err(OPEN_ERR, NULL, data));
	if (ft_read_file(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_parse_map(data->vemap, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
