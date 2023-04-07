/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:18:33 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 17:01:04 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser_bonus.h"

int	set_element(char *line, t_elem elem, t_map_conf *const conf)
{
	int		i;

	if (CEILING <= elem && elem <= FLOOR)
		i = 1;
	else
		i = 2;
	while (is_space(line[i]))
		++i;
	if (CEILING <= elem && elem <= FLOOR)
	{
		if (conf->color_str[elem - CEILING])
			return (set_err(conf, elem, DOUBLE_KEYS));
		conf->color_str[elem - CEILING] = ft_strrtrim(line + i);
	}
	else if (EAST <= elem && elem <= NORTH)
	{
		if (conf->texture_path[elem])
			return (set_err(conf, elem, DOUBLE_KEYS));
		conf->texture_path[elem] = ft_strrtrim(line + i);
	}
	return (SUCCESS);
}

t_elem	get_element_type(char *line)
{
	static const char	*id[6] = {"EA", "WE", "SO", "NO", "C", "F"};
	t_elem				elem;

	elem = EAST;
	while (elem != MAP)
	{
		if (ft_strncmp(line, id[elem], ft_strlen(id[elem])) == 0)
		{
			if (is_space(line[ft_strlen(id[elem])]))
				return (elem);
			else
				return (ELEM_FAIL);
		}
		++elem;
	}
	return (MAP);
}

static void	_set_map_list(char *const line, t_map_conf *conf)
{
	t_list	*cur;
	int		len;
	char	*trimmed;

	cur = NULL;
	trimmed = ft_strrtrim(line);
	if (!trimmed)
	{
		free(line);
		ft_lstclear(&conf->raw_map, free);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	len = ft_strlen(trimmed);
	cur = ft_lstnew(trimmed);
	if (!cur)
	{
		free(line);
		ft_lstclear(&conf->raw_map, free);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	ft_lstadd_back(&conf->raw_map, cur);
	++conf->map_max_height;
	if (conf->map_max_width < len)
		conf->map_max_width = len;
	free(line);
}

static void	_set_first_line(char *const first, t_map_conf *const conf)
{
	char	*trimmed;

	if (!first)
		return ;
	trimmed = ft_strrtrim(first);
	free(first);
	if (!trimmed)
	{
		free_map_conf(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	conf->map_max_width = ft_strlen(trimmed);
	conf->raw_map = ft_lstnew(trimmed);
	if (!conf->raw_map)
	{
		free(trimmed);
		free_map_conf(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	conf->map_max_height = 1;
}

void	set_raw_map(int fd, char *const line, t_map_conf *const conf)
{
	char	*next_line;

	_set_first_line(line, conf);
	next_line = get_next_line(fd);
	while (!is_empty_line(next_line))
	{
		_set_map_list(next_line, conf);
		next_line = get_next_line(fd);
	}
	if (next_line && is_empty_line(next_line))
	{
		free(next_line);
		conf->err_elem = MAP;
		conf->err_msg = "There are empty lines in the map";
	}
}
