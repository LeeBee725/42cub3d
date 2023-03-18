/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 18:30:18 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

static int	_is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (TRUE);
	i = 0;
	while (line[i])
	{
		if (is_space(line[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_elem	_get_element_type(char *line)
{
	static const char	*identifier[6] = {"EA", "WE", "SO", "NO", "C ", "F "};
	t_elem				elem;

	elem = EAST;
	while (elem != MAP)
	{
		if (ft_strncmp(line, identifier[elem], 2) == 0)
			return (elem);
		++elem;
	}
	return (MAP);
}

int	is_space(const unsigned char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

void	init_map_data(t_map_data *const data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture_path[i] = NULL;
		++i;
	}
	data->str_color_ceiling = NULL;
	data->str_color_floor = NULL;
	data->map_width = 0;
	data->map_height = 0;
	data->map = NULL;
}

void	set_map_data(int fd, t_map_data *const data)
{
	char		*line;
	t_elem		elem;

	line = get_next_line(fd);
	while (line)
	{
		if (!_is_empty_line(line))
		{
			elem = _get_element_type(line);
			if (elem == MAP)
				break ;
			set_element(line, elem, data);
		}
		free(line);
		line = get_next_line(fd);
	}
	print_map_data(*data);
	// set_map(fd, line, data);
}

// TODO: remove
#include <stdio.h> // TODO: remove

void	print_map_data(t_map_data data)
{
	int	i;

	printf("Data information\n");
	printf("---------------------------------------------\n");
	printf("EAST_TEXTURE: %s\n", data.texture_path[EAST]);
	printf("WEST_TEXTURE: %s\n", data.texture_path[WEST]);
	printf("SOUTH_TEXTURE: %s\n", data.texture_path[SOUTH]);
	printf("NORTH_TEXTURE: %s\n", data.texture_path[NORTH]);
	printf("CEILING COLOR: %s\n", data.str_color_ceiling);
	printf("FLOOR COLOR: %s\n", data.str_color_floor);
	printf("MAP_WIDTH: %d\n", data.map_width);
	printf("MAP_HEIGHT : %d\n", data.map_height);
	if (!data.map)
	{
		printf("MAP : %s\n", (char *)data.map);
		return ;
	}
	printf("MAP :\n");
	i = 0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		++i;
	}
}
