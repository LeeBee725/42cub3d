/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:56:16 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 22:52:40 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	_set_color(t_color color, const t_elem e)
// {
	
// }
//TODO: set color to config.
void	set_color(t_config *const conf, t_map_data *const data)
{
	if (validate_color_str(data) == FAIL)
		exit_invalid_elem(data, &print_dynamic_err_msg);
	if (validate_color(data, data->str_color_ceiling, CEILING) == FAIL)
		exit_invalid_elem(data, &print_dynamic_err_msg);
	if (validate_color(data, data->str_color_floor, FLOOR) == FAIL)
		exit_invalid_elem(data, &print_dynamic_err_msg);
	conf->color_ceiling.trgb.t = 0;
}
