/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:39:33 by ade-fran          #+#    #+#             */
/*   Updated: 2024/10/02 18:39:35 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_mmap_err(int err, t_program *data)
{
	if (err == MMAP_IMG)
	{
		ft_printf("Error\nMLX: Impossible to create minimap image\n", 2);
		mlx_destroy_window(data->game.mlx, data->game.win);
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
	else if (err == MMAP_ADDR)
	{
		ft_printf("Error\nMLX: Impossible to get minimap address\n", 2);
		mlx_destroy_window(data->game.mlx, data->game.win);
		mlx_destroy_image(data->game.mlx, data->game.minimap.img);
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
}

static void	ft_img_err(int err, t_program *data)
{
	if (err == GAME_IMG)
	{
		ft_printf("Error\nMLX: Impossible to create game image\n", 2);
		mlx_destroy_window(data->game.mlx, data->game.win);
		mlx_destroy_image(data->game.mlx, data->game.minimap.img);
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
	else if (err == GAME_ADDR)
	{
		ft_printf("Error\nMLX: Impossible to get game image address\n", 2);
		mlx_destroy_window(data->game.mlx, data->game.win);
		mlx_destroy_image(data->game.mlx, data->game.minimap.img);
		mlx_destroy_image(data->game.mlx, data->game.img.img);
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
	}
}

int	ft_serv_err(int err, t_program *data)
{
	if (err == SERV_INIT)
		ft_printf("Error\nMLX: Impossible to init mlx serv\n", 2);
	else if (err == WINDOW_ERR)
	{
		ft_printf("Error\nMLX: Impossible to create new window\n", 2);
		free(data->game.mlx);
	}
	else if (err == MMAP_IMG || err == MMAP_ADDR)
		ft_mmap_err(err, data);
	else if (err == GAME_IMG || err == GAME_ADDR)
		ft_img_err(err, data);
	ft_free_parsing(data);
	return (EXIT_FAILURE);
}
