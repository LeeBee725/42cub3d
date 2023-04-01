/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 17:13:28 by sryou            ###   ########.fr       */
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
			if (i == REC_WIDTH - 1 || j == REC_HEIGHT - 1 || \
				i == REC_WIDTH - 2 || j == REC_HEIGHT - 2)
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
	double	distance;
	int		i;

	i = 0;
	while (i < 100)
	{
		if (ray->grid == X_DIRECTION)
			distance = ray->distance_x - ray->delta_distance_x;
		else
			distance = ray->distance_y - ray->delta_distance_y;
		x = ray->user_x + distance * ray->ray_x * ((double)i / 99);
		y = ray->user_y + distance * ray->ray_y * ((double)i / 99);
		put_pixel_to_image(data->img, \
			x * REC_WIDTH, y * REC_HEIGHT, 0x00FF0000);
		i++;
	}
}
