/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:46:35 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 20:59:14 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_empty_line(char *line)
{
	while (*line == ' ' || *line == 9)
		line++;
	if (*line == '\n')
		return (1);
	else
		return (0);
}

int	ft_read_map(char *line, t_vector *vector, t_program *data)
{
	if (ft_check_empty_line(line) && data->first_line == 0)
		return (free(line), EXIT_SUCCESS);
	data->first_line = 1;
	if (ft_vadd(&vector, line) == EXIT_FAILURE)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	return (EXIT_SUCCESS);
}
