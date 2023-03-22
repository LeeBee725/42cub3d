/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 19:38:44 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	exit_with_err(const char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(ERROR);
}

void	exit_with_sys_err(const char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	perror(msg);
	exit(ERROR);
}

void	exit_invalid_element(t_elem invalid, t_map_data *const to_free)
{
	static const char	*msg[7] = {
		INVALID_EAST, INVALID_WEST, INVALID_SOUTH, INVALID_NORTH, \
		INVALID_CEILING, INVALID_FLOOR, INVALID_MAP};
	char				*input;

	input = NULL;
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg[invalid], ft_strlen(msg[invalid]));
	if (EAST <= invalid && invalid <= NORTH)
		input = to_free->texture_path[invalid];
	else if (invalid == CEILING)
		input = to_free->str_color_ceiling;
	else if (invalid == FLOOR)
		input = to_free->str_color_floor;
	if (input)
		write(STDERR_FILENO, input, ft_strlen(input));
	if (to_free->err_msg)
		write(STDERR_FILENO, to_free->err_msg, ft_strlen(to_free->err_msg));
	write(STDERR_FILENO, "\n", 1);
	free_map_data(to_free);
	exit(ERROR);
}
