/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 20:02:55 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ui	**image_to_array(t_img *img)
{
	t_ui	**array;
	int		i;
	int		j;

	if (img->bits_per_pixel != 32 || \
		img->height != TEXTURE_LENGTH || img->width != TEXTURE_LENGTH)
		return (NULL);
	array = malloc(sizeof(t_ui *) * TEXTURE_LENGTH);
	if (!array)
		return (NULL);
	i = 0;
	while (i < TEXTURE_LENGTH)
	{
		array[i] = malloc(sizeof(t_ui) * TEXTURE_LENGTH);
		if (!array[i])
			return (NULL);
		j = 0;
		while (j < TEXTURE_LENGTH)
		{
			array[i][j] = *((t_ui *)(img->addr) + i * TEXTURE_LENGTH + j);
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
	*(t_ui *)tmp = color;
}

void	make_image(t_conf *conf)
{
	t_img	*img;

	img = conf->img;
	img->image = mlx_new_image(conf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, \
		&img->bits_per_pixel, &img->size_line, &img->endian);
}
