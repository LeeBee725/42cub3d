/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:16:26 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*tmp;

	tmp = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
}

void	make_image(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, \
		&img->bits_per_pixel, &img->size_line, &img->endian);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->image);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_handle(int key, t_data *data)
{
	if (key == KEY_EXIT)
		close_window(data);
	if (key == KEY_W)
		move(data, TRUE);
	else if (key == KEY_S)
		move(data, FALSE);
	else if (key == KEY_D)
		rotate(data, TRUE);
	else if (key == KEY_A)
		rotate(data, FALSE);
	else if (key == 53)
		close_window(data);
	return (0);
}
