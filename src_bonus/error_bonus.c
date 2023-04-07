/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:13 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:07 by junhelee         ###   ########.fr       */
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
	write(STDERR_FILENO, ERROR_STR, ft_strlen(ERROR_STR));
	print_err(msg);
	exit(ERROR);
}
