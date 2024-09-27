/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:50:07 by jaung             #+#    #+#             */
/*   Updated: 2024/06/16 16:50:08 by jaung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <sys/time.h>

double	ft_get_time_in_millisecond(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

struct timeval	ft_get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time);
}
