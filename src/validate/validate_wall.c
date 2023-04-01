/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:01:34 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:33:06 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_check(t_conf *const conf, char ***v, const int r, const int c)
{
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};
	int			i;

	if (conf->char_map[r][c] == ' ')
		return (FAIL);
	if (conf->char_map[r][c] == '1')
		return (SUCCESS);
	(*v)[r][c] = '1';
	i = 0;
	while (i < 4)
	{
		if (0 <= r + dy[i] && r + dy[i] < conf->map_height \
			&& 0 <= c + dx[i] && c + dx[i] < conf->map_width)
		{
			if ((*v)[r + dy[i]][c + dx[i]] == '0' && \
				_check(conf, v, r + dy[i], c + dx[i]) == FAIL)
				return (FAIL);
		}
		++i;
	}
	return (SUCCESS);
}

static int	_check_all_path(t_conf *const conf, char ***visitted)
{
	int	r;
	int	c;

	r = 0;
	while (r < conf->map_height)
	{
		c = 0;
		while (c < conf->map_width)
		{
			if ((*visitted)[r][c] == '0' && (conf->char_map[r][c] == '0' \
				|| conf->char_map[r][c] == 'E' || conf->char_map[r][c] == 'W' \
				|| conf->char_map[r][c] == 'S' || conf->char_map[r][c] == 'N'))
				if (_check(conf, visitted, r, c) == FAIL)
					return (FAIL);
			++c;
		}
		++r;
	}
	return (SUCCESS);
}

static char	**_create_visitted_map(const int h, const int w)
{
	char	**visitted;
	int		r;

	visitted = (char **)malloc(sizeof(char *) * (h + 1));
	if (!visitted)
		return (NULL);
	r = 0;
	while (r < h)
	{
		visitted[r] = (char *)malloc(sizeof(char) * (w + 1));
		if (!visitted[r])
		{
			free_2d(visitted);
			return (NULL);
		}
		ft_memset(visitted[r], '0', sizeof(char) * w);
		visitted[r][w] = '\0';
		++r;
	}
	visitted[r] = NULL;
	return (visitted);
}

int	validate_map_surrounded_wall(t_conf *const conf)
{
	char	**visitted;

	visitted = _create_visitted_map(conf->map_height, conf->map_width);
	if (!visitted)
		return (MALLOC_FAIL);
	if (_check_all_path(conf, &visitted) == FAIL)
	{
		free_2d(visitted);
		return (FAIL);
	}
	free_2d(visitted);
	return (SUCCESS);
}
