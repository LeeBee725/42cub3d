/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:18:33 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 18:16:34 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"


void	set_element(char *line, t_elem elem, t_map_data *const data)
{
	int		i;

	line[ft_strlen(line) - 1] = '\0';
	i = 2;
	while (line[i])
	{
		if (!is_space(line[i]))
			break ;
		++i;
	}
	if (elem == CEILING)
		data->str_color_ceiling = ft_strdup(line + i);
	else if (elem == FLOOR)
		data->str_color_floor = ft_strdup(line + i);
	else if (EAST <= elem && elem <= NORTH)
		data->texture_path[elem] = ft_strdup(line + i);
}
