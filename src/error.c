/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 15:14:21 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	print_err_msg(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

void	perror_dynamic_err_msg(const char *msg)
{
	if (!msg)
		return ;
	perror(msg);
	free((void *)msg);
}

void	exit_with_err(const char *msg, void (*print_err)(const char *))
{
	write(STDERR_FILENO, "Error\n", 6);
	print_err(msg);
	exit(ERROR);
}
