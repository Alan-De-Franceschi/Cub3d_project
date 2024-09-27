/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:07:25 by jaung             #+#    #+#             */
/*   Updated: 2024/06/15 16:07:26 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static float	ft_to_radian(float degree)
{
	return ((PI / 180) * degree);
}

float	ft_cos(float degree)
{
	return (cos(ft_to_radian(degree)));
}

float	ft_sin(float degree)
{
	return (sin(ft_to_radian(degree)));
}

float	ft_tan(float degree)
{
	return (tan(ft_to_radian(degree)));
}

void	ft_normalize_vector(double x, double y, t_point *direction)
{
	double	m;

	m = sqrt(x * x + y * y);
	direction->x = x / m;
	direction->y = y / m;
	return ;
}
