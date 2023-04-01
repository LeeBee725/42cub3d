/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:56:16 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:01:04 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_color(t_color *color, t_map_conf *const conf, const t_elem e)
{
	char	**splitted;

	splitted = ft_split(conf->color_str[e - CEILING], ',');
	if (!splitted)
		return (FAIL);
	color->trgb.t = 0;
	color->trgb.r = (unsigned char)ft_atoi(splitted[0]);
	color->trgb.g = (unsigned char)ft_atoi(splitted[1]);
	color->trgb.b = (unsigned char)ft_atoi(splitted[2]);
	color->color |= color->trgb.r << 16;
	color->color |= color->trgb.g << 8;
	color->color |= color->trgb.b;
	free_2d(splitted);
	return (SUCCESS);
}

void	set_color(t_conf *const conf, t_map_conf *const map_conf)
{
	t_elem	e;

	if (validate_color_str(map_conf) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
	e = CEILING;
	while (e <= FLOOR)
	{
		if (validate_color(map_conf, \
			map_conf->color_str[e - CEILING], e) == FAIL)
		{
			free_config(conf);
			exit_invalid_elem(map_conf, &print_dynamic_err_msg);
		}
		if (_set_color(&conf->colors[e - CEILING], map_conf, e) == FAIL)
		{
			free_map_conf(map_conf);
			free_config(conf);
			exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
		}
		++e;
	}
}
