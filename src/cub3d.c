/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:44:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	_close_window(t_conf *conf)
{
	free_config(conf);
	exit(NO_ERROR);
}

int	loop(t_conf *conf)
{
	calculate(conf);
	render(conf);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_conf	conf;

	if (argc < 2)
		exit_with_err(NO_ARGUMENT, &print_err_msg);
	init_conf(&conf);
	set_conf(argv[1], &conf);
	mlx_loop_hook(conf.mlx, &loop, &conf);
	mlx_hook(conf.win, KEY_PRESS, 0, &key_handle, &conf);
	mlx_hook(conf.win, ON_DESTROY, 0, _close_window, &conf);
	mlx_loop(conf.mlx);
	free_config(&conf);
	return (0);
}
