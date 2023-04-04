/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:28:55 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/04 12:30:39 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_img *const img)
{
	if (img)
	{
		img->image = NULL;
		img->width = 0;
		img->height = 0;
		img->addr = NULL;
		img->bits_per_pixel = 0;
		img->size_line = 0;
		img->endian = 0;
	}
}

static void	_set_each_texture(t_conf *const conf, \
	t_map_conf *const map_conf, t_elem elem)
{
	conf->wall[elem].image = mlx_xpm_file_to_image(conf->mlx, \
		map_conf->texture_path[elem], \
		&conf->wall[elem].width, &conf->wall[elem].height);
	if (!conf->wall[elem].image)
	{
		free_config(conf);
		map_conf->err_elem = elem;
		map_conf->err_msg = ft_strjoin(": ", map_conf->texture_path[elem]);
		exit_invalid_elem(map_conf, &perror_dynamic_err_msg);
	}
	conf->wall[elem].addr = mlx_get_data_addr(conf->wall[elem].image, \
		&conf->wall[elem].bits_per_pixel, \
		&conf->wall[elem].size_line, &conf->wall[elem].endian);
	conf->wall_array[elem] = image_to_array(&(conf->wall[elem]));
	if (!conf->wall_array[elem])
	{
		free_config(conf);
		map_conf->err_elem = elem;
		map_conf->err_msg = ft_strjoin(": ", map_conf->texture_path[elem]);
		exit_invalid_elem(map_conf, &perror_dynamic_err_msg);
	}
}

void	set_texture(t_conf *const conf, t_map_conf *const map_conf)
{
	t_elem	elem;

	if (validate_img_ext(map_conf) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
	elem = EAST;
	while (elem <= NORTH)
	{
		_set_each_texture(conf, map_conf, elem);
		++elem;
	}
}
