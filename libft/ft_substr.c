/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:50:25 by junhelee          #+#    #+#             */
/*   Updated: 2022/05/11 09:23:31 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (s)
	{
		i = 0;
		while (i < len)
		{
			result[i] = s[start + i];
			++i;
		}
		result[i] = '\0';
	}
	return (result);
}
