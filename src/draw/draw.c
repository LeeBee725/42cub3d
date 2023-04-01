/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 18:43:18 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rectangle(t_conf *conf, int x, int y, int fill)
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
			draw_rectangle(conf, x, y, conf->map[y][x]);
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

void	draw_map_3d(t_conf *conf)
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
			put_pixel_to_image(conf->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_texture_3d(t_conf *conf, t_ray *ray, int x, int texture_x, int template)
{
	int color;
	double	enlarge;
	int	index;
	int line_height;
	int	start;
	int	end;
	
	enlarge = HEIGHT / TEXTURE_LENGTH;

	line_height = HEIGHT / ray->distance;
	start = HEIGHT / 2 - line_height / 2;
	end = HEIGHT / 2 + line_height / 2;
	index = start;
	if (index < 0)
		index = 0;
	while (index < end && index < HEIGHT)
	{
		int texture_y = (index - start) * TEXTURE_LENGTH / (end - start);
		color = conf->wall_array[template][texture_y][texture_x];
		put_pixel_to_image(conf->img, x, index, color);
		index++;
	}
}

void	draw_object_3d(t_conf *conf, t_ray *ray, int x)
{
	int	template;
	if (ray->grid == X_DIRECTION && ray->step_x > 0)
		template = EAST;
	else if (ray->grid == X_DIRECTION && ray->step_x <= 0)
		template = WEST;
	else if (ray->grid == Y_DIRECTION && ray->step_y > 0)
		template = SOUTH;
	else
		template = NORTH;
	
	double	wall_x;
	if (ray->grid == X_DIRECTION)
		wall_x = ray->user_y + ray->ray_y * ray->distance;
	else
		wall_x = ray->user_x + ray->ray_x * ray->distance;
	wall_x = wall_x - floor(wall_x);

	int		texture_x;
	texture_x = (int)(wall_x * TEXTURE_LENGTH);

	draw_texture_3d(conf, ray, x, texture_x, template);
}
