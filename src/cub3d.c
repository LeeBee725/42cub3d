/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:32 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/17 17:53:02 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(t_data *data)
{
	drawMap(data);
	printf("draw map\n");
	calculate(data);
	printf("calculate\n");
	render(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3d");
	data.img = malloc(sizeof(t_img));
	makeImage(&data);
	
	/* my init code */
	data.map = malloc(sizeof(int *) * 10);
	for (int i = 0;i<10;i++)
		data.map[i] = malloc(sizeof(int) * 18);
	data.map_width = 18;
	data.map_height = 10;

	for (int i=0;i<data.map_height;i++)
		for(int j=0;j<data.map_width;j++)
			data.map[i][j] = 0;
	for (int i=0;i<data.map_height;i++)
	{
		data.map[i][0] = 1;
		data.map[i][data.map_width - 1] = 1;
	}
	for (int i=0;i<data.map_width;i++)
	{
		data.map[0][i] = 1;
		data.map[data.map_height - 1][i] = 1;
	}
	data.map[2][2] = 1;
	data.map[3][5] = 1;
	data.map[7][5] = 1;
	data.map[4][1] = 1;
	data.map[8][10] = 1;
	data.map[3][15] = 1;

	data.camX = -1;
	data.camY = 0;
	data.fovX = 0;
	data.fovY = 0.66;
	data.userX = 10.5;
	data.userY = 7.5;
	data.moveSpeed = 0.08;
	data.rotationSpeed = 0.04;
	printf("init end\n");
	// init end

	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_hook(data.win, KEY_PRESS, 0, &keyHandle, &data);
	mlx_loop(data.mlx);
	return (0);
}
