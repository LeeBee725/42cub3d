/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:24:35 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 19:40:41 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

static int	_is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'W' \
		|| c == 'S' || c == 'N' || c == ' ')
		return (TRUE);
	return (FALSE);
}

//TODO: check that the map has valid characters.
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
