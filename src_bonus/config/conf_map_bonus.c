/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:21 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_set_direction(t_conf *const conf, int axis, int option)
{
	if (axis == X_DIRECTION)
	{
		conf->cam_x = 1 * option;
		conf->cam_y = 0;
		conf->fov_x = 0;
		conf->fov_y = -0.66 * option;
	}
	else
	{
		conf->cam_x = 0;
		conf->cam_y = -1 * option;
		conf->fov_x = -0.66 * option;
		conf->fov_y = 0;
	}
}

static void	_set_user(t_conf *const conf, int x, int y, char direction)
{
	conf->user_x = x + 0.5;
	conf->user_y = y + 0.5;
	if (direction == 'E')
		_set_direction(conf, X_DIRECTION, 1);
	else if (direction == 'W')
		_set_direction(conf, X_DIRECTION, -1);
	else if (direction == 'N')
		_set_direction(conf, Y_DIRECTION, 1);
	else if (direction == 'S')
		_set_direction(conf, Y_DIRECTION, -1);
}

static int	_set_map(t_conf *const conf)
{
	int	i;
	int	j;

	conf->map = (int **)malloc(sizeof(int *) * (conf->map_height));
	if (!conf->map)
		return (FAIL);
	i = 0;
	while (i < conf->map_height)
	{
		conf->map[i] = (int *)malloc(sizeof(int) * (conf->map_width));
		if (!conf->map[i])
			return (FAIL);
		j = 0;
		while (j < conf->map_width)
		{
			if (conf->c_map[i][j] == '1' || conf->c_map[i][j] == ' ')
				conf->map[i][j] = 1;
			else
				conf->map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	set_map(t_conf *const conf)
{
	int	i;
	int	j;

	if (_set_map(conf) == FAIL)
	{
		free_config(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	i = 0;
	while (i < conf->map_height)
	{
		j = 0;
		while (j < conf->map_width)
		{
			if (conf->c_map[i][j] == 'N' || conf->c_map[i][j] == 'S' \
			|| conf->c_map[i][j] == 'E' || conf->c_map[i][j] == 'W')
				_set_user(conf, j, i, conf->c_map[i][j]);
			j++;
		}
		i++;
	}
}
