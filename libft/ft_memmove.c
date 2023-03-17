/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:12:26 by junhelee          #+#    #+#             */
/*   Updated: 2022/05/11 06:00:55 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		if (dst < src)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		else
			*((unsigned char *)dst + len - (i + 1)) \
			= *((unsigned char *)src + len - (i + 1));
		++i;
	}
	return (dst);
}
