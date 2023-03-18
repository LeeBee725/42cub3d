#include "cub3d.h"

void	setStep(t_ray *ray)
{
	if (ray->rayX < 0)
		ray->stepX = -1;
	else
		ray->stepX = 1;
	if (ray->rayY < 0)
		ray->stepY = -1;
	else
		ray->stepY = 1;
}

void	setDistance(t_ray *ray)
{
	if (ray->rayX < 0)
		ray->distanceX = (ray->userX - ray->mapX) * ray->deltaDistanceX;
	else
		ray->distanceX = (ray->mapX + 1 - ray->userX) * ray->deltaDistanceX;
	if (ray->rayY < 0)
		ray->distanceY = (ray->userY - ray->mapY) * ray->deltaDistanceY;
	else
		ray->distanceY = (ray->mapY + 1 - ray->userY) * ray->deltaDistanceY;
}

double	ft_abs(double d)
{
	if (d < 0)
		return -d;
	else
		return d;
}

void	makeRay(int x, t_data *data, t_ray *ray)
{
	double	unit = 2 * x / (double)WIDTH - 1;

	ray->rayX = data->camX + data->fovX * unit;
	ray->rayY = data->camY + data->fovY * unit;
	ray->mapX = data->userX;
	ray->mapY = data->userY;
	ray->userX = data->userX;
	ray->userY = data->userY;
	ray->deltaDistanceX = ft_abs(1 / ray->rayX);
	ray->deltaDistanceY = ft_abs(1 / ray->rayY);
}

void	calculate(t_data *data)
{
	int	x;

	x=0;
	while (x < WIDTH)
	{
		t_ray	ray;
		makeRay(x, data, &ray);
		setStep(&ray);
		setDistance(&ray);

		int hit = FALSE;
		int grid;
		while (hit == FALSE)
		{
			if (ray.distanceX < ray.distanceY)
			{
				ray.distanceX += ray.deltaDistanceX;
				ray.mapX += ray.stepX;
				grid = X_DIRECTION;
			}
			else
			{
				ray.distanceY += ray.deltaDistanceY;
				ray.mapY += ray.stepY;
				grid = Y_DIRECTION;
			}
			if (data->map[ray.mapY][ray.mapX] > 0)
				hit = TRUE;
		}

		if (x%10 == 0)
		{
			printf("grid : %s\n", grid == X_DIRECTION ? "X_DIRECTION": "Y_DIRECTION");
			//printf("%f, %f, %f, %f\n", ray.distanceX, ray.distanceY, ray.rayX, ray.rayY);
			for (int i=0;i<50;i++)
			{
				double myx, myy;
				double distance;
				if (grid == X_DIRECTION)
					distance = ray.distanceX - ray.deltaDistanceX;
				else
					distance = ray.distanceY - ray.deltaDistanceY;

				myx = ray.userX + distance * ray.rayX * ((double)i / 49);
				myy = ray.userY + distance * ray.rayY * ((double)i / 49);
				drawPixel(data, myx * REC_WIDTH, myy * REC_HEIGHT);
				//printf("idx %d : %f, %f\n", i, myx,myy);
			}
		}
		x++;
	}
}