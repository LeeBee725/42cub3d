/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/25 17:16:18 by junhelee         ###   ########.fr       */
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

# define NO_ARGUMENT "Argument not found"
# define NOT_MATCH_EXTENSION "The file extension must be .cub"
# define SYS_FILE_OPEN_FAIL "Open file failed"
# define SYS_HEAP_ALLOCATE_FAIL "Memory allocation failed"

void	print_err_msg(const char *msg);
void	exit_with_err(const char *msg, void (*print_err)(const char *));

#endif
