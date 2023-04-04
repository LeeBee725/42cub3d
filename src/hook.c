/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/04 11:17:39 by junhelee         ###   ########.fr       */
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

// int	key_handle(int key, t_conf *conf)
// {
// 	if (key == KEY_EXIT)
// 		_close_window(conf);
// 	else if (key == KEY_ESC)
// 		_close_window(conf);
// 	if (key == KEY_W)
// 		move(conf, TRUE);
// 	else if (key == KEY_S)
// 		move(conf, FALSE);
// 	else if (key == KEY_D)
// 		rotate(conf, TRUE);
// 	else if (key == KEY_A)
// 		rotate(conf, FALSE);
// 	return (0);
// }

int key_handle(int key, t_conf *conf)
{
	if (key == KEY_EXIT)
		_close_window(conf);
	else if (key == 0xff1b) // ESC
		_close_window(conf);
	if (key == 0x77) // W
		move(conf, TRUE);
	else if (key == 0x73) // S
		move(conf, FALSE);
	else if (key == 0x64) // D
		rotate(conf, TRUE);
	else if (key == 0x61) // A
		rotate(conf, FALSE);
	return (0);
}
