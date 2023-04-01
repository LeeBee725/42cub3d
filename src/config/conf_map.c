/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:48:20 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_map(t_conf *const conf, t_map_conf *const map_conf)
{
	int		i;
	t_list	*cur;

	conf->map_width = map_conf->map_max_width;
	conf->map_height = map_conf->map_max_height;
	conf->char_map = (char **)malloc(sizeof(char *) * (conf->map_height + 1));
	if (!conf->char_map)
		return (FAIL);
	ft_bzero(conf->char_map, sizeof(char *) * (conf->map_height + 1));
	i = 0;
	cur = map_conf->raw_map;
	while (cur && i < conf->map_height)
	{
		conf->char_map[i] = (char *)ft_calloc(conf->map_width + 1, sizeof(char));
		if (!conf->char_map[i])
			return (FAIL);
		ft_memset(conf->char_map[i], ' ', sizeof(char) * conf->map_width);
		ft_strlcpy(conf->char_map[i], (char *)cur->content, \
			ft_strlen((char *)cur->content) + 1);
		if ((size_t)conf->map_width != ft_strlen((char *)cur->content))
			conf->char_map[i][ft_strlen((char *)cur->content)] = ' ';
		cur = cur->next;
		++i;
	}
	return (SUCCESS);
}

static void	_print_map(t_conf *const conf); // TODO: remove after test

void	set_map(t_conf *const conf, t_map_conf *const map_conf)
{
	if (validate_map_has_empty_line(map_conf) == FAIL \
		|| validate_map_char(map_conf) == FAIL \
		|| validate_map_only_one_player(map_conf) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
	if (_set_map(conf, map_conf) == FAIL)
	{
		free_map_conf(map_conf);
		free_config(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	_print_map(conf);
	if (validate_map_surrounded_wall(conf) == FAIL)
	{
		free_config(conf);
		map_conf->err_elem = MAP;
		map_conf->err_msg = ft_strdup(MAP_NOT_SURROUNDED_WALL);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
}

#include <stdio.h> //TODO: remove after test

static void	_print_map(t_conf *const conf) // TODO: remove after test
{
	int	i;

	if (!conf->char_map)
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
	while (conf->char_map[i])
	{
		printf("#%s#\n", conf->char_map[i]);
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
