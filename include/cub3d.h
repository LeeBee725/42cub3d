/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:52:45 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 17:40:31 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define REC_WIDTH 80
# define REC_HEIGHT 80
# define X_DIRECTION 0
# define Y_DIRECTION 1
# define TRUE 1
# define FALSE 0
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
	int		**map;
	int		map_width;
	int		map_height;
	double	camX;
	double	camY;
	double	fovX;
	double	fovY;
	double	userX;
	double	userY;
	double	moveSpeed;
	double	rotationSpeed;
}	t_data;

typedef struct s_ray
{
	double	rayX;
	double	rayY;
	double	userX;
	double	userY;
	int		mapX;
	int		mapY;
	double	distanceX;
	double	distanceY;
	double	deltaDistanceX;
	double	deltaDistanceY;
	int		stepX;
	int 	stepY;
}	t_ray;

void	makeImage(t_data *data);
void	putPixelToImage(t_img *img, int x, int y, int color);
int		keyHandle(int key, t_data *data);

void	drawMap(t_data *data);
void	drawPixel(t_data *data, int x, int y);

void	calculate(t_data *data);
void	render(t_data *data);

#endif