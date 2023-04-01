/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 19:00:24 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_img(void *mlx, t_img *const img)
{
	if (!img)
		return ;
	if (img->image)
		mlx_destroy_image(mlx, img->image);
	if (img->addr)
		free(img->addr);
	free(img);
}

static void	free_2d_unsigned_int(t_ui **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] && i < height)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

static void	free_2d_int(int **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] && i < height)
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

void	free_2d(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		++i;
	}
	free(arr);
	arr = NULL;
}

void	free_config(t_conf *const conf)
{
	int	i;

	free_2d(conf->c_map);
	free_2d_int(conf->map, conf->map_height);
	free_img(conf->mlx, conf->img);
	i = 0;
	while (i < 4)
	{
		free_img(conf->mlx, &conf->wall[i]);
		free_2d_unsigned_int(conf->wall_array[i], 64);
		++i;
	}
	if (conf->win)
		mlx_destroy_window(conf->mlx, conf->win);
	init_conf(conf);
}
