/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:30:11 by junhelee          #+#    #+#             */
/*   Updated: 2022/05/05 17:35:19 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;
	size_t			s_len;

	ch = (unsigned char)c;
	i = 1;
	s_len = ft_strlen(s);
	if (s && !ch)
		return ((char *)s + s_len);
	while (i <= s_len)
	{
		if ((unsigned char)s[s_len - i] == ch)
			return ((char *)s + s_len - i);
		++i;
	}
	return (NULL);
}
