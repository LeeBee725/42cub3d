/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:39 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 19:47:58 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	is_invalid_map_data(t_map_data *const data, t_elem *const invalid)
{
	t_elem	elem;
	char	*texture_path;
	char	*point_pos;

	elem = EAST;
	while (elem <= NORTH)
	{
		texture_path = data->texture_path[elem];
		point_pos = texture_path + ft_strlen(texture_path) + 1 - IMG_EXT_SIZE;
		if (ft_strncmp(point_pos, IMG_EXT, IMG_EXT_SIZE) != 0)
		{
			*invalid = elem;
			data->err_msg = ft_strjoin(": The texture file must be ", IMG_EXT);
			return (TRUE);
		}
		++elem;
	}
	return (FALSE);
}
