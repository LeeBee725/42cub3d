/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:38 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 19:38:28 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "map_parser.h"

# define NO_ERROR 0
# define ERROR 1

# define FAIL_FD -1

# define NO_ARGUMENT "Argument not found"
# define NOT_MATCH_EXTENSION "The file extension must be .cub"
# define SYS_FILE_OPEN_FAIL "Open file failed"

# define INVALID_EAST "Invaild data of EAST wall: "
# define INVALID_WEST "Invaild data of WEST wall: "
# define INVALID_SOUTH "Invaild data of SOUTH wall: "
# define INVALID_NORTH "Invaild data of NORTH wall: "
# define INVALID_CEILING "Invaild data of color of CEILING: "
# define INVALID_FLOOR "Invaild data of color of FLOOR: "
# define INVALID_MAP "Invaild MAP"

void	exit_with_err(const char *msg);
void	exit_with_sys_err(const char *msg);
void	exit_invalid_element(t_elem type, t_map_data *const to_free);

#endif
