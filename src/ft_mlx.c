#include "cub3d.h"

void	putPixelToImage(t_img *img, int x, int y, int color)
{
	char *tmp = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;	
}

void	makeImage(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->image, 
	&img->bits_per_pixel, &img->size_line, &img->endian);
}

static int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	rotate(t_data *data, int clockwise)
{
	double	new_camX;
	double	new_camY;
	double	new_fovX;
	double	new_fovY;

	if (clockwise == TRUE)
		clockwise = 1;
	else
		clockwise = -1;
	new_camX = data->camX * cos(data->rotationSpeed * clockwise)
	- data->camY * sin(data->rotationSpeed * clockwise);
	new_camY = data->camX * sin(data->rotationSpeed * clockwise)
	+ data->camY * cos(data->rotationSpeed * clockwise);
	new_fovX = data->fovX * cos(data->rotationSpeed * clockwise)
	- data->fovY * sin(data->rotationSpeed * clockwise);
	new_fovY = data->fovX * sin(data->rotationSpeed * clockwise)
	+ data->fovY * cos(data->rotationSpeed * clockwise);
	data->camX = new_camX;
	data->camY = new_camY;
	data->fovX = new_fovX;
	data->fovY = new_fovY;
}

int	keyHandle(int key, t_data *data)
{
	if (key == KEY_EXIT)
		close_window(data);
	if (key == KEY_W)
	{
		data->userX += data->camX * data->moveSpeed;
		data->userY += data->camY * data->moveSpeed;
	}
	else if (key == KEY_S)
	{
		data->userX -= data->camX * data->moveSpeed;
		data->userY -= data->camY * data->moveSpeed;
	}
	else if (key == KEY_D)
		rotate(data, TRUE);
	else if (key == KEY_A)
		rotate(data, FALSE);
	return (0);
}
