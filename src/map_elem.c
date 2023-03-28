/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:18:33 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:55 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	set_element(char *line, t_elem elem, t_map_data *const data)
{
	int		i;

	i = 2;
	while (is_space(line[i]))
		++i;
	if (CEILING <= elem && elem <= FLOOR)
	{
		if (data->color_str[elem - CEILING])
		{
			free(data->color_str[elem - CEILING]);
			data->color_str[elem - CEILING] = NULL;
		}
		data->color_str[elem - CEILING] = ft_strrtrim(line + i);
	}
	else if (EAST <= elem && elem <= NORTH)
	{
		if (data->texture_path[elem])
		{
			free(data->texture_path[elem]);
			data->texture_path[elem] = NULL;
		}
		data->texture_path[elem] = ft_strrtrim(line + i);
	}
}

t_elem	get_element_type(char *line)
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

static void	_set_map_list(char *const line, t_map_data *data)
{
	t_list	*cur;
	int		len;
	char	*trimmed;

	cur = NULL;
	trimmed = ft_strrtrim(line);
	if (!trimmed)
	{
		free(line);
		ft_lstclear(&data->raw_map, free);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	len = ft_strlen(trimmed);
	cur = ft_lstnew(trimmed);
	if (!cur)
	{
		free(line);
		ft_lstclear(&data->raw_map, free);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	ft_lstadd_back(&data->raw_map, cur);
	++data->map_max_height;
	if (data->map_max_width < len - 1)
		data->map_max_width = len - 1;
	free(line);
}

static void	_set_first_line(char *const first, t_map_data *const data)
{
	char	*trimmed;

	if (!first)
		return ;
	trimmed = ft_strrtrim(first);
	free(first);
	if (!trimmed)
	{
		free_map_data(data);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	data->map_max_width = ft_strlen(trimmed);
	data->raw_map = ft_lstnew(trimmed);
	if (!data->raw_map)
	{
		free(trimmed);
		free_map_data(data);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	data->map_max_height = 1;
}

void	set_raw_map(int fd, char *const line, t_map_data *const data)
{
	char	*next_line;

	_set_first_line(line, data);
	next_line = get_next_line(fd);
	while (!is_empty_line(next_line))
	{
		_set_map_list(next_line, data);
		next_line = get_next_line(fd);
	}
	if (next_line && is_empty_line(next_line))
		free(next_line);
}
