/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:00:06 by junhelee          #+#    #+#             */
/*   Updated: 2022/10/10 17:24:02 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*result;

	if (!s1)
		return (NULL);
	result = (char *)malloc((n + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, n + 1);
	return (result);
}
