/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:50:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 17:01:06 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser_bonus.h"

int	set_err(t_map_conf *const d, const t_elem e, const char *msg)
{
	d->err_elem = e;
	d->err_msg = ft_strdup(msg);
	return (FAIL);
}

int	set_err_with_res(t_map_conf *const d, const t_elem e, \
	const char *resource, const char *msg)
{
	char	*temp;

	d->err_elem = e;
	temp = ft_strjoin(": ", resource);
	d->err_msg = ft_strjoin(temp, msg);
	free(temp);
	return (FAIL);
}

void	exit_invalid_elem(t_map_conf *const to_free, void (*f)(const char *msg))
{
	static const char	*msg[8] = {
		INVALID_EAST, INVALID_WEST, INVALID_SOUTH, INVALID_NORTH, \
		INVALID_CEILING, INVALID_FLOOR, INVALID_MAP, INVALID_ELEM};
	char				*err_msg;

	if (f == perror_dynamic_err_msg)
		err_msg = ft_strjoin(SYS_FILE_OPEN_FAIL, to_free->err_msg);
	else if (f == perror)
		err_msg = SYS_HEAP_ALLOCATE_FAIL;
	else
		err_msg = ft_strjoin(msg[to_free->err_elem], to_free->err_msg);
	free_map_conf(to_free);
	exit_with_err(err_msg, f);
}

void	print_dynamic_err_msg(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	free((void *)msg);
	write(STDERR_FILENO, "\n", 1);
}
