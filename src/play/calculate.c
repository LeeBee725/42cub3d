/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:46:04 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_distance(t_ray *ray)
{
	double	distance;

	if (ray->grid == X_DIRECTION)
		distance = (ray->distance_x - ray->delta_distance_x);
	else
		distance = (ray->distance_y - ray->delta_distance_y);
	ray->distance = distance;
}

void	calculate_ray(t_conf *conf, t_ray *ray, int x)
{
	int	hit;

	make_ray(conf, ray, x);
	set_step(ray);
	set_distance(ray);
	hit = FALSE;
	while (hit == FALSE)
	{
		if (ray->distance_x < ray->distance_y)
		{
			ray->distance_x += ray->delta_distance_x;
			ray->map_x += ray->step_x;
			ray->grid = X_DIRECTION;
		}
		else
		{
			ray->distance_y += ray->delta_distance_y;
			ray->map_y += ray->step_y;
			ray->grid = Y_DIRECTION;
		}
		if (conf->map[ray->map_y][ray->map_x] > 0)
			hit = TRUE;
	}
}

void	calculate(t_conf *conf)
{
	t_ray	ray;
	int		x;

	draw_map_3d(conf);
	x = 0;
	while (x < WIDTH)
	{
		calculate_ray(conf, &ray, x);
		calculate_distance(&ray);
		draw_object_3d(conf, &ray, WIDTH - x - 1);
		x++;
	}
	draw_map_2d(conf);
	x = 0;
	while (x < WIDTH)
	{
		calculate_ray(conf, &ray, x);
		calculate_distance(&ray);
		if (x % 10 == 0)
			draw_ray_2d(conf, &ray);
		x++;
	}
}
