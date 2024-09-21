/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:48:28 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/27 12:48:30 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	ft_check_argc(int argc, t_program *data)
{
	if (argc < 2)
		return (ft_parsing_err(FEW_ARGS, NULL, data));
	if (argc > 2)
		return (ft_parsing_err(MANY_ARGS, NULL, data));
	return (EXIT_SUCCESS);
}

static int	ft_check_file(char *args, t_program *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (args[i++])
	{
		if (args[i] == '.')
		{
			flag = 1;
			i++;
			if (args[i++] != 'c')
				return (ft_parsing_err(FILE_ERR, NULL, data));
			if (args[i++] != 'u')
				return (ft_parsing_err(FILE_ERR, NULL, data));
			if (args[i++] != 'b')
				return (ft_parsing_err(FILE_ERR, NULL, data));
			break ;
		}
	}
	if (args[i] || flag == 0)
		return (ft_parsing_err(FILE_ERR, NULL, data));
	return (0);
}

int	ft_check_args(char *argv, int argc, t_program *data)
{
	if (ft_check_argc(argc, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_file(argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
