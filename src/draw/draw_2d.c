/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:49:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 11:26:52 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_draw_player(t_conf *conf, t_ray *ray)
{
	int	x;
	int	y;

	y = -REC_HEIGHT / 4;
	while (y < REC_HEIGHT / 4)
	{
		x = -REC_WIDTH / 4;
		while (x < REC_WIDTH / 4)
		{
			put_pixel_to_image(conf->img, \
				(ray->user_x * REC_WIDTH + x), \
				(ray->user_y * REC_HEIGHT + y), BLUE);
			x++;
		}
		y++;
	}
}

static void	_draw_rectangle(t_conf *conf, int x, int y, int fill)
{
	int	color;
	int	i;
	int	j;

	if (fill > 0)
		color = GRAY;
	else
		color = WHITE;
	i = 0;
	while (i < REC_WIDTH)
	{
		j = 0;
		while (j < REC_HEIGHT)
		{
			if (i == REC_WIDTH - 1 || j == REC_HEIGHT - 1)
				put_pixel_to_image(conf->img, x * REC_WIDTH + i, \
					y * REC_HEIGHT + j, BLACK);
			else
				put_pixel_to_image(conf->img, x * REC_WIDTH + i, \
					y * REC_HEIGHT + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_conf *conf)
{
	int	x;
	int	y;

	y = 0;
	while (y < conf->map_height)
	{
		x = 0;
		while (x < conf->map_width)
		{
			_draw_rectangle(conf, x, y, conf->map[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_ray_2d(t_conf *conf, t_ray *ray)
{
	double	x;
	double	y;
	int		i;

	_draw_player(conf, ray);
	i = 0;
	while (i < 40)
	{
		x = ray->user_x + ray->distance * ray->ray_x * ((double)i / 39);
		y = ray->user_y + ray->distance * ray->ray_y * ((double)i / 39);
		put_pixel_to_image(conf->img, \
			x * REC_WIDTH, y * REC_HEIGHT, RED);
		i++;
	}
}
