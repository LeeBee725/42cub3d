/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:50:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 22:21:59 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	set_err(t_map_data *const d, const t_elem e, const char *msg)
{
	d->err_elem = e;
	d->err_msg = ft_strdup(msg);
	return (FAIL);
}

void	exit_invalid_elem(t_map_data *const to_free, void (*f)(const char *msg))
{
	static const char	*msg[7] = {
		INVALID_EAST, INVALID_WEST, INVALID_SOUTH, INVALID_NORTH, \
		INVALID_CEILING, INVALID_FLOOR, INVALID_MAP};
	char				*err_msg;

	if (f == perror)
	{
		free_map_data(to_free);
		exit_with_err(SYS_HEAP_ALLOCATE_FAIL, f);
	}
	err_msg = ft_strjoin(msg[to_free->err_elem], to_free->err_msg);
	free_map_data(to_free);
	exit_with_err(err_msg, f);
}

void	print_dynamic_err_msg(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free((void *)msg);
	write(STDERR_FILENO, "\n", 1);
}
