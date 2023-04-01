/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:44:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_conf *conf, int clockwise)
{
	double	new_cam_x;
	double	new_cam_y;
	double	new_fov_x;
	double	new_fov_y;

	if (clockwise == TRUE)
		clockwise = 1;
	else
		clockwise = -1;
	new_cam_x = conf->cam_x * cos(conf->rotation_speed * clockwise)
		- conf->cam_y * sin(conf->rotation_speed * clockwise);
	new_cam_y = conf->cam_x * sin(conf->rotation_speed * clockwise)
		+ conf->cam_y * cos(conf->rotation_speed * clockwise);
	new_fov_x = conf->fov_x * cos(conf->rotation_speed * clockwise)
		- conf->fov_y * sin(conf->rotation_speed * clockwise);
	new_fov_y = conf->fov_x * sin(conf->rotation_speed * clockwise)
		+ conf->fov_y * cos(conf->rotation_speed * clockwise);
	conf->cam_x = new_cam_x;
	conf->cam_y = new_cam_y;
	conf->fov_x = new_fov_x;
	conf->fov_y = new_fov_y;
}

void	move(t_conf *conf, int foward)
{
	if (foward == TRUE)
		foward = 1;
	else
		foward = -1;
	conf->user_x += conf->cam_x * conf->move_speed * foward;
	conf->user_y += conf->cam_y * conf->move_speed * foward;
}
