/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:00:47 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 18:00:50 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_check_comma(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ',')
		{
			if (line[i + 1] == ',' || line[i + 1] == ' '
			|| line[i + 1] == 9 || line[i + 1] == '\n'
			|| line[i - 1] == ' ' || line[i - 1] == 9)
				return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

static int	ft_fill_colors_array(char **split, int **colors, t_program *data)
{
	int	i;

	i = 0;
	*colors = malloc(sizeof(int) * 3);
	if (!(*colors))
		return (ft_parsing_err(MEM_ERR, NULL, data));
	while (i < 3)
	{
		(*colors)[i] = ft_atoi(split[i + 1], &data->err);
		if (data->err || (*colors)[i] < 0 || (*colors)[i] > 255)
		{
			return (ft_free_strtab(split),
				ft_parsing_err(ATOI_ERR, NULL, data));
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	ft_save_colors(char *line, int **colors, t_program *data)
{
	char	**split;

	if (ft_check_comma(line) == EXIT_FAILURE)
		return (ft_parsing_err(W_PARAM, line, data));
	split = ft_split(line, " ,\n\t");
	if (!split)
		return (ft_parsing_err(SPLIT_MEM, NULL, data));
	if (ft_strtab_len(split) == 4)
	{
		if (ft_fill_colors_array(split, colors, data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		++data->parameters;
	}
	else
		return (ft_free_strtab(split), ft_parsing_err(W_PARAM, line, data));
	return (ft_free_strtab(split), EXIT_SUCCESS);
}
