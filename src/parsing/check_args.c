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

static int	ft_check_argc(int argc)
{
	if (argc < 2)
		return (ft_parsing_err(FEW_ARGS));
	if (argc > 2)
		return (ft_parsing_err(MANY_ARGS));
	return (EXIT_SUCCESS);
}

static int	ft_check_file(char *args)
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
				return (ft_parsing_err(FILE_ERR));
			if (args[i++] != 'u')
				return (ft_parsing_err(FILE_ERR));
			if (args[i++] != 'b')
				return (ft_parsing_err(FILE_ERR));
			break ;
		}
	}
	if (args[i] || flag == 0)
		return (ft_parsing_err(FILE_ERR));
	return (0);
}

int	ft_check_args(char *argv, int argc)
{
	if (ft_check_argc(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_file(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
