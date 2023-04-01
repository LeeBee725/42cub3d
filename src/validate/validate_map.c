/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:24:35 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 23:29:21 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "map_parser.h"

static int	_is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'W' \
		|| c == 'S' || c == 'N' || c == ' ')
		return (TRUE);
	return (FALSE);
}

int	validate_map_has_empty_line(t_map_data *const data)
{
	if (data->err_msg && \
	ft_strncmp(data->err_msg, MAP_INVALID_CHAR, ft_strlen(data->err_msg) + 1))
		return (set_err(data, MAP, MAP_HAS_EMPTY_LINE));
	return (SUCCESS);
}

int	validate_map_char(t_map_data *const data)
{
	t_list	*cur;
	int		i;

	cur = data->raw_map;
	while (cur)
	{
		i = 0;
		while ((char *)cur->content && ((char *)cur->content)[i])
		{
			if (!_is_valid_char(((char *)cur->content)[i]))
				return (set_err_with_res(data, MAP, \
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

int	validate_map_only_one_player(t_map_data *const data)
{
	t_list	*cur;
	int		i;
	int		player_flag;
	char	*line;

	cur = data->raw_map;
	player_flag = 0;
	while (cur)
	{
		i = 0;
		line = (char *)cur->content;
		while (line && line[i])
		{
			if (_is_player_char(line[i]))
			{
				if (player_flag)
					return (set_err_with_res(data, MAP, line, \
							MAP_NOT_ONLY_ONE));
				player_flag = 1;
			}
			++i;
		}
		cur = cur->next;
	}
	return (SUCCESS);
}
