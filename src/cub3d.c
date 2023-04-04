/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/04 11:21:31 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_conf	conf;

	if (argc < 2)
		exit_with_err(NO_ARGUMENT, &print_err_msg);
	init_conf(&conf);
	set_conf(argv[1], &conf);
	// mlx_hook(conf.win, KEY_PRESS, 0, &key_handle, &conf);
	mlx_hook(conf.win, 2, (1L << 0) | (1L << 1), &key_handle, &conf); // TODO: remove until test This is for linux
	mlx_loop_hook(conf.mlx, &loop, &conf);
	mlx_loop(conf.mlx);
	return (NO_ERROR);
}
