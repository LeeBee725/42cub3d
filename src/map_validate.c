/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:39 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 17:17:00 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

static int	is_invalid_img_ext(t_map_data *const data, t_elem *const invalid)
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

static int	_is_invalid_color_str(const char *color_str)
{
	(void)color_str;
	return (FALSE);
}

static int	_is_invalid_color(t_map_data *const data, t_elem *const invalid)
{
	int	res;

	res = _is_invalid_color_str(data->str_color_ceiling);
	if (res)
	{
		if (res == FAIL)
		{
			free_map_data(data);
			exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
		}
		*invalid = CEILING;
		return (TRUE);
	}
	res = _is_invalid_color_str(data->str_color_floor);
	if (res)
	{
		if (res == FAIL)
		{
			free_map_data(data);
			exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
		}
		*invalid = FLOOR;
		return (TRUE);
	}
	return (FALSE);
}

static int	_is_invalid_raw_map(t_map_data *const data, t_elem *const invalid)
{
	*invalid = MAP;
	(void)data;
	(void)invalid;
	return (FALSE);
}

int	is_invalid_map_data(t_map_data *const data, t_elem *const invalid)
{
	if (is_invalid_img_ext(data, invalid) \
		|| _is_invalid_color(data, invalid) \
		|| _is_invalid_raw_map(data, invalid))
		return (TRUE);
	return (FALSE);
}
