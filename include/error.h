/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 16:30:40 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define NO_ERROR 0
# define ERROR 1

# define FAIL_FD -1

# define NO_ARGUMENT "Argument not found."
# define NAT_MATCH_EXTENSION "The file extension must be \".cub\"."
# define SYS_FILE_OPEN_FAIL "Open file failed"

int	print_err(const char *msg);
int	print_sys_err(const char *msg);

#endif
