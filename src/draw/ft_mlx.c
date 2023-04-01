/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:49:25 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*tmp;

	tmp = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
}

void	make_image(t_conf *conf)
{
	t_img	*img;

	img = conf->img;
	img->image = mlx_new_image(conf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, \
		&img->bits_per_pixel, &img->size_line, &img->endian);
}

int	close_window(t_conf *conf)
{
	mlx_destroy_image(conf->mlx, conf->img->image);
	mlx_destroy_window(conf->mlx, conf->win);
	exit(0);
}

int	key_handle(int key, t_conf *conf)
{
	if (key == KEY_EXIT)
		close_window(conf);
	if (key == KEY_W)
		move(conf, TRUE);
	else if (key == KEY_S)
		move(conf, FALSE);
	else if (key == KEY_D)
		rotate(conf, TRUE);
	else if (key == KEY_A)
		rotate(conf, FALSE);
	else if (key == 53)
		close_window(conf);
	return (0);
}
