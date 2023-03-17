/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 19:30:52 by junhelee         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef enum e_elem_type {
	CEIL,
	FLOOR,
	WALL_EAST,
	WALL_WEST,
	WALL_SOUTH,
	WALL_NORTH,
	MAP
}	t_elem_type;

typedef enum e_orient {
	EAST,
	WEST,
	SOUTH,
	NORTH
}	t_orient;

typedef struct s_trgb {
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_trgb;

typedef union s_color {
	int		color;
	t_trgb	trgb;
}	t_color;

typedef struct s_data {
	void			*mlx;
	void			*win;
	unsigned int	width;
	unsigned int	height;
	char			**map;
	void			*img_wall[4];
	t_color			color_f;
	t_color			color_c;
}	t_data;

void	init_data(char *const file_name, t_data *const data);
void	set_map_data(int fd, t_data *const data);

#endif