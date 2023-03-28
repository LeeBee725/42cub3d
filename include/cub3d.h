/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/28 17:26:48 by junhelee         ###   ########.fr       */
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

# define WIN_TITLE "cub3D"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define ON_DESTROY 17

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
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_config {
	void			*mlx;
	void			*win;
	t_image			wall[4];
	t_color			colors[2];
	int				map_width;
	int				map_height;
	char			**map;
}	t_config;

//	config.c
void	init_config(t_config *const data);
void	free_config(t_config *const conf);
void	set_config(char *const file_name, t_config *const data);

//	conf_error.c
void	exit_validate_fail(t_config *const conf, t_map_data *const data);

//	conf_color.c
void	set_color(t_config *const conf, t_map_data *const data);

//	conf_image.c
void	set_texture(t_config *const conf, t_map_data *const data);

#endif