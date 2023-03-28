/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:39 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 14:22:22 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	validate_img_ext(t_map_data *const data)
{
	t_elem	elem;
	char	*texture_path;
	char	*point_pos;

	elem = EAST;
	while (elem <= NORTH)
	{
		texture_path = data->texture_path[elem];
		if (!texture_path)
			return (set_err(data, elem, "This path is NULL"));
		point_pos = texture_path + ft_strlen(texture_path) + 1 - IMG_EXT_SIZE;
		if (ft_strncmp(point_pos, IMG_EXT, IMG_EXT_SIZE) != 0)
		{
			data->err_elem = elem;
			data->err_msg = ft_strjoin(": The texture file must be ", IMG_EXT);
			return (FAIL);
		}
		++elem;
	}
	return (SUCCESS);
}
