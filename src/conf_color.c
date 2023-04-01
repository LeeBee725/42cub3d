/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:56:16 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:09:34 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_color(t_color *color, t_map_data *const data, const t_elem e)
{
	char	**splitted;

	splitted = ft_split(data->color_str[e - CEILING], ',');
	if (!splitted)
		return (FAIL);
	color->trgb.t = 0;
	color->trgb.r = (unsigned char)ft_atoi(splitted[0]);
	color->trgb.g = (unsigned char)ft_atoi(splitted[1]);
	color->trgb.b = (unsigned char)ft_atoi(splitted[2]);
	free_2d(splitted);
	return (SUCCESS);
}

void	set_color(t_data *const conf, t_map_data *const data)
{
	t_elem	e;

	if (validate_color_str(data) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(data, &print_dynamic_err_msg);
	}
	e = CEILING;
	while (e <= FLOOR)
	{
		if (validate_color(data, data->color_str[e - CEILING], e) == FAIL)
		{
			free_config(conf);
			exit_invalid_elem(data, &print_dynamic_err_msg);
		}
		if (_set_color(&conf->colors[e - CEILING], data, e) == FAIL)
		{
			free_map_data(data);
			free_config(conf);
			exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
		}
		++e;
	}
}
