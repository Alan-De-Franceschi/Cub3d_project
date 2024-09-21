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

#include "cube.h"

static int	ft_check_path(char *path, t_program *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n%s: ", 2, path);
		return (ft_parsing_err(PATH_ERR, NULL, data));
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_save_path(char *line, char **path, t_program *data)
{
	char	**split;

	split = ft_split(line, " \n\t");
	if (!split)
		return(ft_parsing_err(SPLIT_MEM, NULL, data));
	if (ft_strtab_len(split) == 2 && ft_strncmp(split[1], "./", 2) == 0)
	{
		*path = ft_strdup(split[1]);
		if (!(*path))
		{
			return (ft_free_strtab(split),
				ft_parsing_err(MEM_ERR, NULL, data));
		}
		++data->parameters;
	}
	else
		return (ft_free_strtab(split), ft_parsing_err(W_PARAM, line, data));
	return (ft_free_strtab(split), ft_check_path(*path, data));
}
