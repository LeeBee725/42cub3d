/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 16:57:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data *data, int clockwise)
{
	double	new_cam_x;
	double	new_cam_y;
	double	new_fov_x;
	double	new_fov_y;

	if (clockwise == TRUE)
		clockwise = 1;
	else
		clockwise = -1;
	new_cam_x = data->cam_x * cos(data->rotation_speed * clockwise)
		- data->cam_y * sin(data->rotation_speed * clockwise);
	new_cam_y = data->cam_x * sin(data->rotation_speed * clockwise)
		+ data->cam_y * cos(data->rotation_speed * clockwise);
	new_fov_x = data->fov_x * cos(data->rotation_speed * clockwise)
		- data->fov_y * sin(data->rotation_speed * clockwise);
	new_fov_y = data->fov_x * sin(data->rotation_speed * clockwise)
		+ data->fov_y * cos(data->rotation_speed * clockwise);
	data->cam_x = new_cam_x;
	data->cam_y = new_cam_y;
	data->fov_x = new_fov_x;
	data->fov_y = new_fov_y;
}

void	move(t_data *data, int foward)
{
	if (foward == TRUE)
		foward = 1;
	else
		foward = -1;
	data->user_x += data->cam_x * data->move_speed * foward;
	data->user_y += data->cam_y * data->move_speed * foward;
}
