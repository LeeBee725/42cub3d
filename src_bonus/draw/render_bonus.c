/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 17:01:02 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render(t_conf *conf)
{
	mlx_put_image_to_window(conf->mlx, conf->win, conf->img->image, 0, 0);
}
