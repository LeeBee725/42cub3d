/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 19:46:28 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_is_empty_line(char *line)
{
	size_t	i;

	if (line == NULL)
		return (TRUE);
	i = 0;
	while (line[i])
	{
		if (line[i] != '\t' && line[i] != ' ' && line[i] != '\n' && \
			line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static t_elem_type	_detact_type(char *line)
{
	static const char *const	elems[6] = {"C ", "F ", "EA", "WE", "SO", "NO"};
	t_elem_type					type;

	type = CEIL;
	while (elems[type])
	{
		if (ft_strncmp(elems[type], line, 2) == 0)
			return (type);
		++type;
	}
	return (MAP);
}

void	set_map_data(int fd, t_data *const data)
{
	char		*line;
	t_elem_type	type;

	line = get_next_line(fd);
	while (line)
	{
		if (!_is_empty_line(line))
		{
			type = _detact_type(line);
			printf("%s", line);
			printf("%d\n", type);
		}
		free(line);
		line = get_next_line(fd);
	}
	(void)data;
}
