/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:51:20 by ade-fran          #+#    #+#             */
/*   Updated: 2024/09/21 17:51:21 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_load_assets(char *path, t_data *view, t_program *data)
{
	int	weight;
	int	height;

	view->img = mlx_xpm_file_to_image(data->game.mlx, path, &weight, &height);
	if (!view->img)
		return (ft_assets_err(LOAD_ASSET, path, data));
	view->addr = (int *)mlx_get_data_addr(view->img, &view->bits_per_pixel,
			&view->line_length, &view->endian);
	if (!view->addr)
		return (ft_assets_err(ASSET_ADDR, path, data));
	return (EXIT_SUCCESS);
}

int	ft_save_path(char *line, t_data *view, t_program *data, int *param)
{
	char	**split;

	if (*param)
		return (ft_parsing_err(DUP_PARAM, line, data));
	split = ft_split(line, " \n\t");
	if (!split)
		return (ft_parsing_err(SPLIT_MEM, NULL, data));
	if (ft_strtab_len(split) == 2 && ft_strncmp(split[1], "./", 2) == 0)
	{
		if (ft_load_assets(split[1], view, data) == EXIT_FAILURE)
			return (ft_free_strtab(split), EXIT_FAILURE);
		++data->parameters;
	}
	else
		return (ft_free_strtab(split), ft_parsing_err(W_PARAM, line, data));
	*param = 1;
	return (ft_free_strtab(split), EXIT_SUCCESS);
}
