#include "fractol.h"

void	putpixel(int x, int y, unsigned int color, t_img *img)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	b = (color & 0xFF) >> 0;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF0000) >> 16;
	if (img->endian == 0)
	{
		if (img->data[(y * img->sl) + x * (img->bpp / 8)] != b)
			img->data[(y * img->sl) + x * (img->bpp / 8)] = b;
		if (img->data[(y * img->sl) + x * (img->bpp / 8) + 1] != g)
			img->data[(y * img->sl) + x * (img->bpp / 8) + 1] = g;
		if (img->data[(y * img->sl) + x * (img->bpp / 8) + 2] != r)
			img->data[(y * img->sl) + x * (img->bpp / 8) + 2] = r;
	}
	else
	{
		img->data[y * img->sl + x * img->bpp / 8] = (color & 0xFF) >> 0;
		img->data[y * img->sl + x * img->bpp / 8 + 1] = (color & 0xFF00) >> 8;
		img->data[y * img->sl + x * img->bpp / 8 + 2] =
			(color & 0xFF0000) >> 16;
	}
}
