/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 13:50:10 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_data *data)
{
	calculate(data);
	render(data);
	return (0);
}

void	my_init(t_data *data)
{
	int	i;
	int	j;
	/* my init code */
	data->map = malloc(sizeof(int *) * 10);
	i = 0;
	while (i < 10)
		data->map[i++] = malloc(sizeof(int) * 18);
	data->map_width = 18;
	data->map_height = 10;
	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			data->map[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		data->map[i][0] = 1;
		data->map[i][data->map_width - 1] = 1;
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		data->map[0][i] = 1;
		data->map[data->map_height - 1][i] = 1;
		i++;
	}
	data->map[2][2] = 1;
	data->map[3][5] = 1;
	data->map[7][5] = 1;
	data->map[4][1] = 1;
	data->map[8][10] = 1;
	data->map[3][15] = 1;
	data->cam_x = -1;
	data->cam_y = 0;
	data->fov_x = 0;
	data->fov_y = 0.66;
	data->user_x = 10.5;
	data->user_y = 7.5;
	data->move_speed = 0.08;
	data->rotation_speed = 0.04;
	printf("init end\n");
	// init end
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	data.img = malloc(sizeof(t_img));
	make_image(&data);
	my_init(&data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_hook(data.win, KEY_PRESS, 0, &key_handle, &data);
	mlx_loop(data.mlx);
	return (0);
}
