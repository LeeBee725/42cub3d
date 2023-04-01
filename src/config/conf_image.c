/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:28:55 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:47:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		conf->wall[elem].image = mlx_xpm_file_to_image(\
				conf->mlx, map_conf->texture_path[elem], \
				&conf->wall[elem].width, &conf->wall[elem].height);
		if (!conf->wall[elem].image)
		{
			free_config(conf);
			map_conf->err_elem = elem;
			map_conf->err_msg = ft_strjoin(": ", map_conf->texture_path[elem]);
			exit_invalid_elem(map_conf, &perror_dynamic_err_msg);
		}
		++elem;
	}
}
