/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 18:45:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_conf *conf)
{
	int x;
	//TODO: Please remove after test
	x = 0;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[EAST].image, x, 0);
	x += conf->wall[EAST].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[WEST].image, x, 0);
	x += conf->wall[WEST].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[SOUTH].image, x, 0);
	x += conf->wall[SOUTH].width;
	mlx_put_image_to_window(conf->mlx, conf->win, conf->wall[NORTH].image, x, 0);
}

int	main(int argc, char *argv[])
{
	t_conf	conf;

	if (argc < 2)
		exit_with_err(NO_ARGUMENT, &print_err_msg);
	init_conf(&conf);
	set_conf(argv[1], &conf);
	mlx_hook(conf.win, KEY_PRESS, 0, &key_handle, &conf);
	mlx_loop_hook(conf.mlx, &loop, &conf);
	mlx_loop(conf.mlx);
	return (NO_ERROR);
}
