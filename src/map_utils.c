/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:51:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 17:04:12 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	is_space(const unsigned char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || \
		c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (TRUE);
	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}
