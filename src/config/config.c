/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:44:28 by sryou            ###   ########.fr       */
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
		conf->wall[i].image = NULL;
		conf->wall[i].width = 0;
		conf->wall[i].height = 0;
		++i;
	}
	conf->colors[0].color = 0;
	conf->colors[1].color = 0;
	conf->map_width = 0;
	conf->map_height = 0;
	conf->char_map = NULL;
}

void	free_config(t_conf *const conf)
{
	int	i;

	i = 0;
	if (conf->char_map)
		free_2d(conf->char_map);
	i = 0;
	while (i < 4)
	{
		if (conf->wall[i].image)
			mlx_destroy_image(conf->mlx, conf->wall[i].image);
		++i;
	}
	if (conf->win)
		mlx_destroy_window(conf->mlx, conf->win);
	init_conf(conf);
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
	int	x;

	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, WIDTH, HEIGHT, WIN_TITLE);
	conf->img = malloc(sizeof(t_img));
	make_image(conf);
	set_texture(conf, map_conf);
	set_color(conf, map_conf);
	set_map(conf, map_conf);
	//TODO: Please remove after test
	x = 0;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[EAST].image, x, 0);
	x += conf->wall[EAST].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[WEST].image, x, 0);
	x += conf->wall[WEST].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[SOUTH].image, x, 0);
	x += conf->wall[SOUTH].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[NORTH].image, x, 0);
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
