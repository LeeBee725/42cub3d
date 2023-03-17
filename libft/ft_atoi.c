/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:04:09 by junhelee          #+#    #+#             */
/*   Updated: 2022/05/11 06:06:23 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	return (uc == '\t' || uc == '\n' || uc == '\v'
		|| uc == '\f' || uc == '\r' || uc == ' ');
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	long long		sum;

	sum = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while (ft_isdigit(str[i]))
	{
		if (sum * sign > MAX_INT)
			return (-1);
		else if (sum * sign < MIN_INT)
			return (0);
		sum = sum * 10 + str[i] - '0';
		++i;
	}
	return ((int)(sum * sign));
}
