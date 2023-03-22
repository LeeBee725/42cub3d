/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 20:50:03 by junhelee         ###   ########.fr       */
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
