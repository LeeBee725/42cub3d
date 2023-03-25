/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:28:39 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 22:52:50 by junhelee         ###   ########.fr       */
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

int	_validate_color_str(t_map_data *const data, const char *str, const t_elem e)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != ',' && (str[i] < '0' || '9' < str[i]))
			return (set_err(data, e, "Undefined character"));
		if (str[i] == ',')
			++cnt;
		++i;
	}
	if (cnt != 2)
		return (set_err(data, e, "Wrong number of comma"));
	if (i > 11)
		return (set_err(data, e, "String is too long"));
	return (SUCCESS);
}

int	validate_color_str(t_map_data *const data)
{
	if (!data->str_color_ceiling)
		return (set_err(data, CEILING, "This value is NULL"));
	if (!data->str_color_floor)
		return (set_err(data, FLOOR, "This value is NULL"));
	if (_validate_color_str(data, data->str_color_ceiling, CEILING) == FAIL)
		return (FAIL);
	if (_validate_color_str(data, data->str_color_floor, FLOOR) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

//TODO: Norm
int	validate_color(t_map_data *const data, const char *str, const t_elem e)
{
	char	**splitted;
	int		i;
	int		val;

	splitted = ft_split(str, ',');
	if (!splitted)
		exit_invalid_elem(data, &perror);
	i = 0;
	while (splitted[i])
	{
		if (splitted[i][0] == '0' && splitted[i][1] != '\0')
		{
			free_2d(splitted);
			return (set_err(data, e, "Weird zero"));
		}
		val = ft_atoi(splitted[i]);
		if (val < 0 || 255 < val)
		{
			free_2d(splitted);
			return (set_err(data, e, "Color value is out of range"));
		}
		++i;
	}
	if (i != 3)
	{
		free_2d(splitted);
		return (set_err(data, e, "Number of value is wrong"));
	}
	free_2d(splitted);
	return (SUCCESS);
}
