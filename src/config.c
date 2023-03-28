/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 19:27:02 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_config(t_config *const conf)
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
		if (conf->wall[i].image)
			mlx_destroy_image(conf->mlx, conf->wall[i].image);
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
		exit_with_err(NOT_MATCH_EXTENSION, &print_err_msg);
}

static void	_set_config(t_config *const conf, t_map_data *const map_data)
{
	int	x;

	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	set_texture(conf, map_data);
	set_color(conf, map_data);
	set_map(conf, map_data); //TODO: setting_map
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

void	set_config(char *const file_name, t_config *const conf)
{
	int			fd;
	t_map_data	map_data;

	init_map_data(&map_data);
	_check_extension(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == FAIL_FD)
		exit_with_err(SYS_FILE_OPEN_FAIL, &perror);
	set_map_data(fd, &map_data);
	close(fd);
	_set_config(conf, &map_data);
	free_map_data(&map_data);
}
