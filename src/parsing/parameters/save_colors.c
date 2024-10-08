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

#include "cub3d.h"

static int	ft_check_comma(char *line, t_program *data)
{
	char	**test;
	int		i;

	test = ft_split(line, " \t\n");
	if (!test)
		return (ft_parsing_err(MEM_ERR, NULL, data));
	if (ft_strtab_len(test) != 2)
		return (ft_free_strtab(&test), ft_parsing_err(W_PARAM, line, data));
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ',')
		{
			if (line[i + 1] == ',' || line[i + 1] == ' ' || line[i + 1] == 9
				|| line[i + 1] == '\n' || line[i - 1] == ' ' || line[i
					- 1] == 9)
				return (ft_free_strtab(&test), ft_parsing_err(W_PARAM, line,
						data));
		}
		++i;
	}
	return (ft_free_strtab(&test), EXIT_SUCCESS);
}

static int	*ft_fill_colors_array(char **split, t_program *data)
{
	int	i;
	int	*colors;

	i = 0;
	colors = malloc(sizeof(int) * 3);
	if (!(colors))
	{
		ft_parsing_err(MEM_ERR, NULL, data);
		return (NULL);
	}
	while (i < 3)
	{
		colors[i] = ft_atoi(split[i + 1], &data->err);
		if (data->err || colors[i] < 0 || colors[i] > 255)
		{
			ft_parsing_err(ATOI_ERR, NULL, data);
			free(colors);
			return (ft_free_strtab(&split), NULL);
		}
		++i;
	}
	return (colors);
}

static void	ft_get_hexa(int *array, int *color)
{
	*color = 255 << 24 | array[0] << 16 | array[1] << 8 | array[2];
}

int	ft_save_colors(char *line, int *color, t_program *data, int *param)
{
	char	**split;
	int		*colors_array;

	if (*param)
		return (ft_parsing_err(DUP_PARAM, line, data));
	if (ft_check_comma(line, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	split = ft_split(line, " ,\n\t");
	if (!split)
		return (ft_parsing_err(SPLIT_MEM, NULL, data));
	if (ft_strtab_len(split) == 4)
	{
		colors_array = ft_fill_colors_array(split, data);
		if (!colors_array)
			return (EXIT_FAILURE);
		ft_get_hexa(colors_array, color);
		free(colors_array);
		++data->parameters;
	}
	else
		return (ft_free_strtab(&split), ft_parsing_err(W_PARAM, line, data));
	*param = 1;
	return (ft_free_strtab(&split), EXIT_SUCCESS);
}
