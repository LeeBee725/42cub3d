/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:30:44 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:31:00 by junhelee         ###   ########.fr       */
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

void	make_ray(t_conf *conf, t_ray *ray, int x)
{
	double	unit;

	unit = 2 * x / (double)WIDTH - 1;
	ray->ray_x = conf->cam_x + conf->fov_x * unit;
	ray->ray_y = conf->cam_y + conf->fov_y * unit;
	ray->map_x = conf->user_x;
	ray->map_y = conf->user_y;
	ray->user_x = conf->user_x;
	ray->user_y = conf->user_y;
	ray->delta_distance_x = fabs(1 / ray->ray_x);
	ray->delta_distance_y = fabs(1 / ray->ray_y);
}
