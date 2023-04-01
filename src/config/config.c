/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 18:53:21 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_conf(t_conf *const conf)
{
	int	i;

	conf->win = NULL;
	i = 0;
	while (i < 4)
	{
		init_img(&conf->wall[i]);
		++i;
	}
	conf->colors[0].color = 0;
	conf->colors[1].color = 0;
	conf->img = NULL;
	conf->map_width = 0;
	conf->map_height = 0;
	conf->move_speed = 0.08;
	conf->rotation_speed = 0.04;
	conf->cam_x = 0;
	conf->cam_y = 0;
	conf->fov_x = 0;
	conf->fov_y = 0;
	conf->c_map = NULL;
	conf->map = NULL;
}

static void	_check_extension(const char *const file_name)
{
	const char	*point_pos;
	int			fail;

	point_pos = file_name + ft_strlen(file_name) + 1 - 5;
	fail = ft_strncmp(point_pos, ".cub", 5);
	if (fail)
		exit_with_err(NOT_MATCH_EXTENSION, &print_err_msg);
}

static void	_set_conf(t_conf *const conf, t_map_conf *const map_conf)
{
	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, WIDTH, HEIGHT, WIN_TITLE);
	conf->img = malloc(sizeof(t_img));
	make_image(conf);
	set_texture(conf, map_conf);
	set_color(conf, map_conf);
	set_charmap(conf, map_conf);
	set_map(conf);
}

void	set_conf(char *const file_name, t_conf *const conf)
{
	int			fd;
	t_map_conf	map_conf;

	init_map_conf(&map_conf);
	_check_extension(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == FAIL_FD)
		exit_with_err(SYS_FILE_OPEN_FAIL, &perror);
	set_map_conf(fd, &map_conf);
	close(fd);
	_set_conf(conf, &map_conf);
	free_map_conf(&map_conf);
}
