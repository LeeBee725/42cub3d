/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 11:30:47 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"
# include "error.h"
# include "map_parser.h"

# define WIN_TITLE "cub3D"
# define WIDTH 1920
# define HEIGHT 1080
# define REC_WIDTH 20
# define REC_HEIGHT 20
# define TEXTURE_LENGTH 64
# define X_DIRECTION 0
# define Y_DIRECTION 1
# define TRUE 1
# define FALSE 0
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GRAY 0x00555555
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define KEY_PRESS 2
# define ON_DESTROY 17
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SEG_NUM 6

typedef unsigned int	t_ui;

typedef struct s_trgb {
	unsigned char	t;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_trgb;

typedef struct s_color {
	int		color;
	t_trgb	trgb;
}	t_color;

typedef struct s_img
{
	void	*image;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_conf {
	t_img	wall[4];
	t_color	colors[2];
	char	**c_map;
	int		**map;
	void	*mlx;
	void	*win;
	t_ui	**wall_array[4];
	t_img	*img;
	double	cam_x;
	double	cam_y;
	double	fov_x;
	double	fov_y;
	double	user_x;
	double	user_y;
	double	move_speed;
	double	rotation_speed;
	int		map_width;
	int		map_height;
}	t_conf;

typedef struct s_ray
{
	double	ray_x;
	double	ray_y;
	double	user_x;
	double	user_y;
	int		map_x;
	int		map_y;
	double	distance;
	double	distance_x;
	double	distance_y;
	double	delta_distance_x;
	double	delta_distance_y;
	int		step_x;
	int		step_y;
	int		grid;
}	t_ray;

//	config/conf_cmap.c
void	set_charmap(t_conf *const conf, t_map_conf *const map_conf);

//	config/conf_color.c
void	set_color(t_conf *const conf, t_map_conf *const map_conf);

//	config/conf_free.c
void	free_2d(char **arr);
void	free_config(t_conf *const conf);

//	config/conf_image.c
void	init_img(t_img *const img);
void	set_texture(t_conf *const conf, t_map_conf *const map_conf);

//	config/conf_map.c
void	set_map(t_conf *const conf);

//	config/config.c
void	init_conf(t_conf *const conf);
void	set_conf(char *const file_name, t_conf *const conf);

//	draw/draw_2d.c
void	draw_map_2d(t_conf *conf);
void	draw_ray_2d(t_conf *conf, t_ray *ray);

//	draw/draw_3d.c
void	draw_map_3d(t_conf *conf);
void	draw_object_3d(t_conf *conf, t_ray *ray, int x);

//	draw/image.c
t_ui	**image_to_array(t_img *img);
void	make_image(t_conf *conf);
void	put_pixel_to_image(t_img *img, int x, int y, int color);

//	draw/render.c
void	render(t_conf *conf);

//	play/calculate.c
void	calculate(t_conf *conf);

//	play/move.c
void	move(t_conf *conf, int foward, int horizen);
void	rotate(t_conf *conf, int clockwise);

//	play/ray.c
void	set_step(t_ray *ray);
void	set_distance(t_ray *ray);
void	make_ray(t_conf *conf, t_ray *ray, int x);

//	validate/validate_wall.c
int		validate_map_surrounded_wall(t_conf *const conf);

//	hook.c
int		loop(t_conf *conf);
int		key_handle(int key, t_conf *conf);
int		close_window(t_conf *conf);

#endif
