/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_img_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:39 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:11 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_img_ext(t_map_conf *const conf)
{
	t_elem	elem;
	char	*texture_path;
	char	*point_pos;

	elem = EAST;
	while (elem <= NORTH)
	{
		texture_path = conf->texture_path[elem];
		if (!texture_path)
			return (set_err(conf, elem, VALUE_IS_NULL));
		point_pos = texture_path + ft_strlen(texture_path) + 1 - IMG_EXT_SIZE;
		if (ft_strncmp(point_pos, IMG_EXT, IMG_EXT_SIZE) != 0)
		{
			conf->err_elem = elem;
			conf->err_msg = ft_strjoin(IMG_MUST_BE, IMG_EXT);
			return (FAIL);
		}
		++elem;
	}
	return (SUCCESS);
}
