/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 17:11:42 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

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
	data->map_max_width = 0;
	data->map_max_height = 0;
	data->raw_map = NULL;
}

void	free_map_data(t_map_data *const data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(data->texture_path[i]);
		++i;
	}
	free(data->str_color_ceiling);
	free(data->str_color_floor);
	ft_lstclear(&data->raw_map, free);
	init_map_data(data);
}

static void	_increase_map_size(t_map_data *data, int line_width)
{
	++data->map_max_height;
	if (data->map_max_width < line_width - 1)
		data->map_max_width = line_width - 1;
}

static void	_set_raw_map(int fd, char *const line, t_map_data *data)
{
	t_list	*cur;
	char	*next_line;
	int		line_len;

	data->raw_map = ft_lstnew(line);
	if (!data->raw_map)
		return ;
	data->map_max_height = 1;
	next_line = get_next_line(fd);
	while (!is_empty_line(next_line))
	{
		cur = ft_lstnew(next_line);
		if (!cur)
		{
			ft_lstclear(&data->raw_map, free);
			return ;
		}
		ft_lstadd_back(&data->raw_map, cur);
		line_len = ft_strlen(next_line);
		_increase_map_size(data, line_len);
		next_line = get_next_line(fd);
	}
	if (next_line && is_empty_line(next_line))
		free(next_line);
}

void	set_map_data(int fd, t_map_data *const data)
{
	char		*line;
	t_elem		elem;

	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			elem = get_element_type(line);
			if (elem == MAP)
				break ;
			set_element(line, elem, data);
		}
		free(line);
		line = get_next_line(fd);
	}
	_set_raw_map(fd, line, data);
	print_map_data(*data);
}

// TODO: remove
#include <stdio.h> // TODO: remove

void	print_map_data(t_map_data data)
{
	t_list	*cur;

	printf("Data information\n");
	printf("---------------------------------------------\n");
	printf("EAST_TEXTURE: %s\n", data.texture_path[EAST]);
	printf("WEST_TEXTURE: %s\n", data.texture_path[WEST]);
	printf("SOUTH_TEXTURE: %s\n", data.texture_path[SOUTH]);
	printf("NORTH_TEXTURE: %s\n", data.texture_path[NORTH]);
	printf("CEILING COLOR: %s\n", data.str_color_ceiling);
	printf("FLOOR COLOR: %s\n", data.str_color_floor);
	printf("MAP_WIDTH: %d\n", data.map_max_width);
	printf("MAP_HEIGHT : %d\n", data.map_max_height);
	if (!data.raw_map)
	{
		printf("MAP : %s\n", (char *)data.raw_map);
		return ;
	}
	printf("MAP :\n");
	cur = data.raw_map;
	while (cur)
	{
		printf("%s\n", (char *)cur->content);
		cur = cur->next;
	}
}
