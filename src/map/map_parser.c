/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:55:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:44:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	init_map_conf(t_map_conf *const conf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		conf->texture_path[i] = NULL;
		++i;
	}
	conf->color_str[0] = NULL;
	conf->color_str[1] = NULL;
	conf->err_msg = NULL;
	conf->err_elem = MAP;
	conf->map_max_width = 0;
	conf->map_max_height = 0;
	conf->raw_map = NULL;
}

void	free_map_conf(t_map_conf *const conf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(conf->texture_path[i]);
		++i;
	}
	free(conf->color_str[0]);
	free(conf->color_str[1]);
	if (conf->err_msg)
		free(conf->err_msg);
	ft_lstclear(&conf->raw_map, free);
	init_map_conf(conf);
}

void	set_map_conf(int fd, t_map_conf *const conf)
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
			set_element(line, elem, conf);
		}
		free(line);
		line = get_next_line(fd);
	}
	set_raw_map(fd, line, conf);
	print_map_conf(*conf);// TODO: remove
}

// TODO: remove
#include <stdio.h> // TODO: remove

void	print_map_conf(t_map_conf conf)
{
	t_list	*cur;

	printf("conf information\n");
	printf("---------------------------------------------\n");
	printf("EAST_TEXTURE: %s\n", conf.texture_path[EAST]);
	printf("WEST_TEXTURE: %s\n", conf.texture_path[WEST]);
	printf("SOUTH_TEXTURE: %s\n", conf.texture_path[SOUTH]);
	printf("NORTH_TEXTURE: %s\n", conf.texture_path[NORTH]);
	printf("CEILING COLOR: %s\n", conf.color_str[CEILING - CEILING]);
	printf("FLOOR COLOR: %s\n", conf.color_str[FLOOR - CEILING]);
	printf("MAP_WIDTH: %d\n", conf.map_max_width);
	printf("MAP_HEIGHT : %d\n", conf.map_max_height);
	if (!conf.raw_map)
	{
		printf("MAP : %s\n", "(null)");
		return ;
	}
	printf("MAP :\n");
	cur = conf.raw_map;
	while (cur)
	{
		printf("%s\n", (char *)cur->content);
		cur = cur->next;
	}
}
