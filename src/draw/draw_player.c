/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:49:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 17:50:17 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_conf *conf, t_ray *ray)
{
	int	x;
	int	y;

	y = -REC_HEIGHT / 4;
	while (y < REC_HEIGHT / 4)
	{
		x = -REC_WIDTH / 4;
		while (x < REC_WIDTH / 4)
		{
			put_pixel_to_image(conf->img, \
				(ray->user_x * REC_WIDTH + x), \
				(ray->user_y * REC_HEIGHT + y), BLUE);
			x++;
		}
		y++;
	}
}
