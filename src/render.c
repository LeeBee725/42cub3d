#include "cub3d.h"

void	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->image, 0, 0);
}