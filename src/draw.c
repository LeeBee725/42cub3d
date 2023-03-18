#include "cub3d.h"

void	drawRectangle(t_data *data, int x, int y, int fill)
{
	int color;
	if (fill > 0)
		color = 0x00555555;
	else
		color = 0x00FFFFFF;
	for (int i = 0; i < REC_WIDTH; i++)
	{
		for (int j = 0; j < REC_HEIGHT; j++)
		{
			if (i == REC_WIDTH - 1 || j == REC_HEIGHT - 1 || i == REC_WIDTH - 2 || j == REC_HEIGHT - 2)
				putPixelToImage(data->img, x * REC_WIDTH + i, y * REC_HEIGHT + j, 0x00000000);
			else
				putPixelToImage(data->img, x * REC_WIDTH + i, y * REC_HEIGHT + j, color);
		}
	}
}

void	drawMap(t_data *data)
{
	for (int y=0;y < data->map_height;y++) {
		for (int x=0;x < data->map_width;x++) {
			drawRectangle(data, x, y, data->map[y][x]);
		}
	}
}

void	drawPixel(t_data *data, int x, int y)
{
	int color = 0x00FF0000;
	putPixelToImage(data->img, x, y, color);
}
