/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:50:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 19:08:28 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	exit_invalid_elem(t_map_data *const to_free, void (*f)(const char *msg))
{
	static const char	*msg[7] = {
		INVALID_EAST, INVALID_WEST, INVALID_SOUTH, INVALID_NORTH, \
		INVALID_CEILING, INVALID_FLOOR, INVALID_MAP};
	char				*err_msg;

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
