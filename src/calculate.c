/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 13:54:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_step(t_ray *ray)
{
	if (ray->ray_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	set_distance(t_ray *ray)
{
	if (ray->ray_x < 0)
		ray->distance_x = (ray->user_x - ray->map_x) * \
			ray->delta_distance_x;
	else
		ray->distance_x = (ray->map_x + 1 - ray->user_x) * \
			ray->delta_distance_x;
	if (ray->ray_y < 0)
		ray->distance_y = (ray->user_y - ray->map_y) * \
			ray->delta_distance_y;
	else
		ray->distance_y = (ray->map_y + 1 - ray->user_y) * \
			ray->delta_distance_y;
}

void	make_ray(t_data *data, t_ray *ray, int x)
{
	double	unit;

	unit = 2 * x / (double)WIDTH - 1;
	ray->ray_x = data->cam_x + data->fov_x * unit;
	ray->ray_y = data->cam_y + data->fov_y * unit;
	ray->map_x = data->user_x;
	ray->map_y = data->user_y;
	ray->user_x = data->user_x;
	ray->user_y = data->user_y;
	ray->delta_distance_x = fabs(1 / ray->ray_x);
	ray->delta_distance_y = fabs(1 / ray->ray_y);
}

void	calculate_distance(t_ray *ray)
{
	double	distance;
	
	if (ray->grid == X_DIRECTION)
		distance = (ray->distance_x - ray->delta_distance_x);
	else
		distance = (ray->distance_y - ray->delta_distance_y);
	ray->distance = distance;
}

void	calculate_ray(t_data *data, t_ray *ray, int x)
{
	int	hit;

	make_ray(data, ray, x);
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
		if (data->map[ray->map_y][ray->map_x] > 0)
			hit = TRUE;
	}
}

void	calculate(t_data *data)
{
	t_ray	ray;
	int		x;

	draw_map_3d(data);
	x = 0;
	while (x < WIDTH)
	{
		calculate_ray(data, &ray, x);
		calculate_distance(&ray);
		draw_object_3d(data, &ray, WIDTH - x - 1);
		x++;
	}
	draw_map_2d(data);
	x = 0;
	while (x < WIDTH)
	{
		calculate_ray(data, &ray, x);
		calculate_distance(&ray);
		if (x % 10 == 0)
			draw_ray_2d(data, &ray);
		x++;
	}
}
