/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:02:24 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(t_data *data, int x, int y, int fill)
{
	int	color;
	int	i;
	int	j;

	if (fill > 0)
		color = 0x00555555;
	else
		color = 0x00FFFFFF;
	i = 0;
	while (i < REC_WIDTH)
	{
		j = 0;
		while (j < REC_HEIGHT)
		{
			if (i == REC_WIDTH - 1 || j == REC_HEIGHT - 1)
				put_pixel_to_image(data->img, x * REC_WIDTH + i, \
					y * REC_HEIGHT + j, 0x00000000);
			else
				put_pixel_to_image(data->img, x * REC_WIDTH + i, \
					y * REC_HEIGHT + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			draw_rectangle(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_ray_2d(t_data *data, t_ray *ray)
{
	double	x;
	double	y;
	int		i;

	y = -REC_HEIGHT / 4;
	while (y < REC_HEIGHT / 4)
	{
		x = -REC_WIDTH / 4;
		while (x < REC_WIDTH / 4)
		{
			put_pixel_to_image(data->img, \
				(ray->user_x * REC_WIDTH + x), \
				(ray->user_y * REC_HEIGHT + y), BLUE);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < 40)
	{
		x = ray->user_x + ray->distance * ray->ray_x * ((double)i / 39);
		y = ray->user_y + ray->distance * ray->ray_y * ((double)i / 39);
		put_pixel_to_image(data->img, \
			x * REC_WIDTH, y * REC_HEIGHT, RED);
		i++;
	}
}

void	draw_map_3d(t_data *data)
{
	int	color;
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				color = 0x0050BCDF;
			else
				color = 0x00AAAAAA;
			put_pixel_to_image(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_object_3d(t_data *data, t_ray *ray, int x)
{
	int	line_height;
	int	start;
	int	end;

	line_height = HEIGHT / ray->distance;
	start = HEIGHT / 2 - line_height / 2;
	end = HEIGHT / 2 + line_height / 2;
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	while (start <= end)
	{
		if (ray->grid == X_DIRECTION)
			put_pixel_to_image(data->img, x, start, 0x008B2D2B);
		else
			put_pixel_to_image(data->img, x, start, 0x00723838);
		start++;
	}
}
