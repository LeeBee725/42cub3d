/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:51:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 11:13:15 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char	*ft_strrtrim(const char *str)
{
	int		i;
	char	*trimmed;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (!str[i] || is_space(str[i]))
		--i;
	trimmed = (char *)malloc(sizeof(char) * (i + 1 + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, str, i + 1 + 1);
	return (trimmed);
}
