/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:30:11 by junhelee          #+#    #+#             */
/*   Updated: 2022/10/10 11:37:50 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	ch = c;
	if (!s)
		return (NULL);
	if (s && !ch)
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == ch)
			return ((char *)s + i);
		++i;
	}
	return (NULL);
}
