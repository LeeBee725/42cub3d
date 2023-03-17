/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:38:52 by junhelee          #+#    #+#             */
/*   Updated: 2022/03/23 15:53:29 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	bytes;

	bytes = count * size;
	mem = malloc(bytes);
	if (!mem)
		return (NULL);
	ft_bzero(mem, bytes);
	return (mem);
}
