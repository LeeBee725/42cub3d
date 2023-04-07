/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 15:35:06 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_conf *conf)
{
	free_config(conf);
	exit(NO_ERROR);
}

void	move_mouse(t_conf *conf)
{
	int	w_per_seg;
	int	x;
	int	y;

	w_per_seg = WIDTH / SEG_NUM;
	mlx_mouse_get_pos(conf->win, &x, &y);
	if (0 <= x && x <= w_per_seg && 0 <= y && y <= HEIGHT)
		rotate(conf, FALSE);
	else if (WIDTH - w_per_seg <= x && x <= WIDTH && 0 <= y && y <= HEIGHT)
		rotate(conf, TRUE);
}

int	loop(t_conf *conf)
{
	calculate(conf);
	render(conf);
	move_mouse(conf);
	return (0);
}

int	key_handle(int key, t_conf *conf)
{
	if (key == KEY_ESC)
		close_window(conf);
	if (key == KEY_W)
		move(conf, TRUE, FALSE);
	else if (key == KEY_S)
		move(conf, FALSE, FALSE);
	else if (key == KEY_A)
		move(conf, TRUE, TRUE);
	else if (key == KEY_D)
		move(conf, FALSE, TRUE);
	else if (key == KEY_RIGHT)
		rotate(conf, TRUE);
	else if (key == KEY_LEFT)
		rotate(conf, FALSE);
	return (0);
}
