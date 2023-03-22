/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 20:53:42 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_config(t_config *const conf)
{
	int	i;

	conf->mlx = NULL;
	conf->win = NULL;
	i = 0;
	while (i < 4)
	{
		conf->wall_img[i].instance = NULL;
		conf->wall_img[i].width = 0;
		conf->wall_img[i].height = 0;
		++i;
	}
	conf->color_ceiling.color = 0;
	conf->color_floor.color = 0;
	conf->map_width = 0;
	conf->map_height = 0;
	conf->map = NULL;
}

void	free_config(t_config *const conf)
{
	int	i;

	i = 0;
	if (conf->map)
	{
		while (conf->map[i])
		{
			free(conf->map[i]);
			++i;
		}
		free(conf->map);
	}
	i = 0;
	while (i < 4)
	{
		if (conf->wall_img[i].instance)
			mlx_destroy_image(conf->mlx, conf->wall_img[i].instance);
		++i;
	}
	if (conf->win)
		mlx_destroy_window(conf->mlx, conf->win);
	init_config(conf);
}

static void	_check_extension(const char *const file_name)
{
	const char	*point_pos;
	int			fail;

	point_pos = file_name + ft_strlen(file_name) + 1 - 5;
	fail = ft_strncmp(point_pos, ".cub", 5);
	if (fail)
		exit_with_err(NOT_MATCH_EXTENSION);
}

static void	_set_config(t_config *const conf, t_map_data *const map_data)
{
	t_elem		invalid;

	if (is_invalid_map_data(map_data, &invalid))
		exit_invalid_element(invalid, map_data);
	(void)conf;
}

void	set_config(char *const file_name, t_config *const conf)
{
	int			fd;
	t_map_data	map_data;

	init_map_data(&map_data);
	_check_extension(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == FAIL_FD)
		exit_with_sys_err(SYS_FILE_OPEN_FAIL);
	set_map_data(fd, &map_data);
	close(fd);
	_set_config(conf, &map_data);
	free_map_data(&map_data);
}
