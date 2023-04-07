/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:19 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				color = conf->colors[0].color;
			else
				color = conf->colors[1].color;
			put_pixel_to_image(conf->img, x, y, color);
			x++;
		}
		y++;
	}
}

static double	_get_wall_x(t_ray *ray)
{
	double	wall_x;

	if (ray->grid == X_DIRECTION)
		wall_x = ray->user_y + ray->ray_y * ray->distance;
	else
		wall_x = ray->user_x + ray->ray_x * ray->distance;
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}

static t_elem	_get_elem(t_ray *ray)
{
	t_elem	elem;

	if (ray->grid == X_DIRECTION && ray->step_x > 0)
		elem = EAST;
	else if (ray->grid == X_DIRECTION && ray->step_x <= 0)
		elem = WEST;
	else if (ray->grid == Y_DIRECTION && ray->step_y > 0)
		elem = SOUTH;
	else
		elem = NORTH;
	return (elem);
}

void	draw_object_3d(t_conf *conf, t_ray *ray, int x)
{
	t_elem	elem;
	int		texture_x;
	int		texture_y;
	int		meta[3];

	elem = _get_elem(ray);
	texture_x = (int)(_get_wall_x(ray) * TEXTURE_LENGTH);
	meta[1] = HEIGHT / 2 - (HEIGHT / ray->distance) / 2;
	meta[2] = HEIGHT / 2 + (HEIGHT / ray->distance) / 2;
	meta[0] = meta[1];
	if (meta[0] < 0)
		meta[0] = 0;
	while (meta[0] < meta[2] && meta[0] < HEIGHT)
	{
		texture_y = (meta[0] - meta[1]) * TEXTURE_LENGTH / (meta[2] - meta[1]);
		put_pixel_to_image(conf->img, x, meta[0], \
			conf->wall_array[elem][texture_y][texture_x]);
		meta[0]++;
	}
}
