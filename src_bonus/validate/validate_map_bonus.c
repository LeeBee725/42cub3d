/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:24:35 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 17:01:15 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	_is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'W' \
		|| c == 'S' || c == 'N' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	validate_map_has_empty_line(t_map_conf *const conf)
{
	if (conf->err_msg && \
	ft_strncmp(conf->err_msg, MAP_INVALID_CHAR, ft_strlen(conf->err_msg) + 1))
		return (set_err(conf, MAP, MAP_HAS_EMPTY_LINE));
	return (SUCCESS);
}

int	validate_map_char(t_map_conf *const conf)
{
	t_list	*cur;
	int		i;

	cur = conf->raw_map;
	while (cur)
	{
		i = 0;
		while ((char *)cur->content && ((char *)cur->content)[i])
		{
			if (!_is_valid_char(((char *)cur->content)[i]))
				return (set_err_with_res(conf, MAP, \
							((char *)cur->content), MAP_INVALID_CHAR));
			++i;
		}
		cur = cur->next;
	}
	return (SUCCESS);
}

static int	_is_player_char(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (TRUE);
	return (FALSE);
}

int	validate_map_one_player(t_map_conf *const conf)
{
	t_list	*cur;
	int		i;
	int		player_cnt;
	char	*line;

	cur = conf->raw_map;
	player_cnt = 0;
	while (cur)
	{
		i = 0;
		line = (char *)cur->content;
		while (line && line[i])
		{
			if (player_cnt && _is_player_char(line[i]))
				return (set_err_with_res(conf, MAP, line, \
						MAP_NOT_ONLY_ONE));
			if (_is_player_char(line[i]))
				++player_cnt;
			++i;
		}
		cur = cur->next;
	}
	if (!player_cnt)
		return (set_err(conf, MAP, MAP_NO_PLAYER));
	return (SUCCESS);
}
