/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:34:22 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int**	image_to_array(t_img *img)
{
	unsigned int**	array;
	int				i;
	int				j;
	
	if (img->bits_per_pixel != 32 || img->height != 64 || img->width != 64)
		return (NULL);
	array = (unsigned int **)malloc(sizeof(unsigned int *) * 64);
	if (!array)
		return (NULL);
	i = 0;
	while (i < 64)
	{
		array[i] = (unsigned int *)malloc(sizeof(unsigned int) * 64);
		if (!array[i])
			return (NULL);
		j = 0;
		while (j < 64)
		{
			array[i][j] = *((unsigned int *)(img->addr) + i * 64 + j);
			j++;
		}
		i++;
	}
	return (array);
}

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
