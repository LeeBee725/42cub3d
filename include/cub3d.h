/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 16:15:42 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"
# include "error.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
}	t_data;

void	init_data(char *const file_name);

#endif