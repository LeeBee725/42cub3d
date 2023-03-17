/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:40:25 by junhelee          #+#    #+#             */
/*   Updated: 2022/03/30 19:05:45 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	int_abs_str[10];
	char	*pos;

	ft_bzero(int_abs_str, 10);
	if (n == MIN_INT)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	pos = int_abs_str + 10;
	if (n >= 0)
	{
		while (n / 10)
		{
			*(--pos) = n % 10 + '0';
			n = n / 10;
		}
		*(--pos) = n % 10 + '0';
		write(fd, pos, int_abs_str + 10 - pos);
	}
}
