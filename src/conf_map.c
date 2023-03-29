/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 22:09:31 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_map(t_config *const conf, t_map_data *const data)
{
	int		i;
	t_list	*cur;

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
		conf->map[i] = (char *)ft_calloc(conf->map_width + 1, sizeof(char));
		if (!conf->map[i])
			return (FAIL);
		ft_memset(conf->map[i], ' ', sizeof(char) * conf->map_width);
		ft_strlcpy(conf->map[i], (char *)cur->content, \
			ft_strlen((char *)cur->content) + 1);
		if ((size_t)conf->map_width != ft_strlen((char *)cur->content))
			conf->map[i][ft_strlen((char *)cur->content)] = ' ';
		cur = cur->next;
		++i;
	}
	return (SUCCESS);
}

static void	_print_map(t_config *const conf); // TODO: remove after test

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
	while (i < conf->map_width + 2)
	{
		printf("#");
		++i;
	}
	printf("\n");
	i = 0;
	while (conf->map[i])
	{
		printf("#%s#\n", conf->map[i]);
		++i;
	}
	i = 0;
	while (i < conf->map_width + 2)
	{
		printf("#");
		++i;
	}
	printf("\n");
}
