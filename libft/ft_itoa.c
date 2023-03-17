/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:46:37 by junhelee          #+#    #+#             */
/*   Updated: 2022/03/30 17:54:14 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_place(int n, int base)
{
	size_t	place;

	place = 0;
	while (n / base)
	{
		++place;
		n = n / base;
	}
	return (place);
}

static char	*allocate_num_str_size(long long abs_n, int sign, size_t *len)
{
	size_t			place;
	char			*result;

	if (sign == -1)
		++(*len);
	place = count_place(abs_n, 10);
	*len += place + 1;
	result = (char *)malloc((*len + 1) * sizeof(char));
	return (result);
}

char	*ft_itoa(int n)
{
	int				sign;
	long long		abs_n;
	size_t			num_str_len;
	char			*num_str;

	sign = 1;
	if (n < 0)
		sign = -1;
	abs_n = (long long)n * sign;
	num_str_len = 0;
	num_str = allocate_num_str_size(abs_n, sign, &num_str_len);
	if (!num_str)
		return (NULL);
	num_str[num_str_len] = '\0';
	while (abs_n / 10)
	{
		num_str[--num_str_len] = abs_n % 10 + '0';
		abs_n = abs_n / 10;
	}
	num_str[--num_str_len] = abs_n % 10 + '0';
	if (num_str_len > 0)
		num_str[--num_str_len] = '-';
	return (num_str);
}
