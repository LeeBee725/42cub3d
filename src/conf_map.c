/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 16:54:18 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_map(t_config *const conf, t_map_data *const data)
{
	int		i;
	t_list	*cur;
	char	*line;

	conf->map_width = data->map_max_width;
	conf->map_height = data->map_max_height;
	conf->map = (char **)malloc(sizeof(char *) * (conf->map_height + 1));
	if (!conf->map)
		return (FAIL);
	ft_bzero(conf->map, sizeof(char *) * (conf->map_height + 1));
	i = 0;
	cur = data->raw_map;
	while (cur && i < conf->map_height)
	{
		line = (char *)cur->content;
		conf->map[i] = (char *)malloc(sizeof(char) * (conf->map_width + 1));
		if (!conf->map[i])
			return (FAIL);
		ft_memset(conf->map[i], ' ', sizeof(char) * (conf->map_width + 1));
		conf->map[i][conf->map_width] = '\0';
		ft_strlcpy(conf->map[i], line, ft_strlen(line));
		cur = cur->next;
		++i;
	}
	return (SUCCESS);
}

static void	_print_map(t_config *const conf); // TODO: remove after test

//TODO: setting map
void	set_map(t_config *const conf, t_map_data *const data)
{
	if (validate_map_has_empty_line(data) == FAIL \
		|| validate_map_char(data) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(data, &print_dynamic_err_msg);
	}
	if (_set_map(conf, data) == FAIL)
	{
		free_map_data(data);
		free_config(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	_print_map(conf);
}

#include <stdio.h> //TODO: remove after test

static void	_print_map(t_config *const conf) // TODO: remove after test
{
	int	i;

	if (!conf->map)
	{
		printf("Map:(null)\n");
		return ;
	}
	printf("Map:\n");
	i = 0;
	while (conf->map[i])
	{
		printf("%s\n", conf->map[i]);
		++i;
	}
}
