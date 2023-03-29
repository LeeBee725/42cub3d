/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:24:35 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 23:01:56 by junhelee         ###   ########.fr       */
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
