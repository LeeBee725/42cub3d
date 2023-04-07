/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_cmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:14:25 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 10:41:01 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_set_charmap(t_conf *const conf, t_map_conf *const map_conf)
{
	int		i;
	t_list	*cur;

	conf->map_width = map_conf->map_max_width;
	conf->map_height = map_conf->map_max_height;
	conf->c_map = (char **)malloc(sizeof(char *) * (conf->map_height + 1));
	if (!conf->c_map)
		return (FAIL);
	ft_bzero(conf->c_map, sizeof(char *) * (conf->map_height + 1));
	i = 0;
	cur = map_conf->raw_map;
	while (cur && i < conf->map_height)
	{
		conf->c_map[i] = (char *)ft_calloc(conf->map_width + 1, sizeof(char));
		if (!conf->c_map[i])
			return (FAIL);
		ft_memset(conf->c_map[i], ' ', sizeof(char) * conf->map_width);
		ft_strlcpy(conf->c_map[i], (char *)cur->content, \
			ft_strlen((char *)cur->content) + 1);
		if ((size_t)conf->map_width != ft_strlen((char *)cur->content))
			conf->c_map[i][ft_strlen((char *)cur->content)] = ' ';
		cur = cur->next;
		++i;
	}
	return (SUCCESS);
}

void	set_charmap(t_conf *const conf, t_map_conf *const map_conf)
{
	if (validate_map_has_empty_line(map_conf) == FAIL \
		|| validate_map_char(map_conf) == FAIL \
		|| validate_map_one_player(map_conf) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
	if (_set_charmap(conf, map_conf) == FAIL)
	{
		free_map_conf(map_conf);
		free_config(conf);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, &perror);
	}
	if (validate_map_surrounded_wall(conf) == FAIL)
	{
		free_config(conf);
		map_conf->err_elem = MAP;
		map_conf->err_msg = ft_strdup(MAP_NOT_SURROUNDED_WALL);
		exit_invalid_elem(map_conf, &print_dynamic_err_msg);
	}
}
