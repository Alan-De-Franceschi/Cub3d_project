/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:51:10 by ade-fran          #+#    #+#             */
/*   Updated: 2024/08/27 12:51:12 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_parsing_err(int err)
{
	if (err == FILE_ERR)
		ft_putstr_fd("Args: Invalid filename", 2);
	if (err == FEW_ARGS)
		ft_putstr_fd("Args: Too few arguments", 2);
	if (err == MANY_ARGS)
		ft_putstr_fd("Args: Too many arguments", 2);
	return (1);
}
