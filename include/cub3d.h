/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 17:48:04 by junhelee         ###   ########.fr       */
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
# include "map_parser.h"

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

typedef struct s_image {
	void	*instance;
	int		width;
	int		height;
}	t_image;

typedef struct s_config {
	void			*mlx;
	void			*win;
	t_image			wall_img[4];
	t_color			color_ceiling;
	t_color			color_floor;
	int				map_width;
	int				map_height;
	char			**map;
}	t_config;

void	init_config(char *const file_name, t_config *const data);

#endif