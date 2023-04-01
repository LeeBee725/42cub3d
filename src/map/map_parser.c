/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 15:25:10 by junhelee         ###   ########.fr       */
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
	data->color_str[0] = NULL;
	data->color_str[1] = NULL;
	data->err_msg = NULL;
	data->err_elem = MAP;
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
	free(data->color_str[0]);
	free(data->color_str[1]);
	if (data->err_msg)
		free(data->err_msg);
	ft_lstclear(&data->raw_map, free);
	init_map_data(data);
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
	set_raw_map(fd, line, data);
	print_map_data(*data);// TODO: remove
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
	printf("CEILING COLOR: %s\n", data.color_str[CEILING - CEILING]);
	printf("FLOOR COLOR: %s\n", data.color_str[FLOOR - CEILING]);
	printf("MAP_WIDTH: %d\n", data.map_max_width);
	printf("MAP_HEIGHT : %d\n", data.map_max_height);
	if (!data.raw_map)
	{
		printf("MAP : %s\n", "(null)");
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
