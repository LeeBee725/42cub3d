/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 13:23:57 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_close_window(t_config *conf)
{
	free_config(conf);
	exit(NO_ERROR);
}

static int	_handle_key_event(int keycode, t_config *conf)
{
	if (keycode == 53) // ESC
		_close_window(conf);
	return (NO_ERROR);
}

int	main(int argc, char *argv[])
{
	t_config	conf;

	if (argc < 2)
		exit_with_err(NO_ARGUMENT, &print_err_msg);
	init_config(&conf);
	set_config(argv[1], &conf);
	mlx_hook(conf.win, ON_DESTROY, 0, _close_window, &conf);
	mlx_hook(conf.win, 2, 0, _handle_key_event, &conf);
	mlx_loop(conf.mlx);
	free_config(&conf);
	return (NO_ERROR);
}
