#include "fractol.h"
#include <math.h>

static void		ft_select_color(char type, int *color)
{
	if (type == 1)
		*color = 0x00FFFFFF;
	if (type == 2)
		*color = 0x00FF0000;
	if (type == 3)
		*color = 0x0000FF00;
	if (type == 4)
		*color = 0x000000FF;
	if (type == 5)
		*color = 0x0000FFFF;
	if (type == 6)
		*color = 0x00FFFF00;
	if (type == 7)
		*color = 0x00FF00FF;
	if (type == 16)
		*color = 0;
}

static int		ft_select_bgcolor(char type)
{
	if (type == 9)
		return (0x00FF0000);
	if (type == 10)
		return (0x0000FF00);
	if (type == 11)
		return (0x000000FF);
	if (type == 12)
		return (0x0000FFFF);
	if (type == 13)
		return (0x00FFFF00);
	if (type == 14)
		return (0x00FF00FF);
	if (type == 15)
		return (0x00FFFFFF);
	if (type == 17)
		return (0);
	return (0);
}

static int		ft_get_color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

static int		ft_extract_color(char c, int color)
{
	if (c == 'r')
		return ((color & 0x00FF0000) >> 16);
	if (c == 'g')
		return ((color & 0x0000FF00) >> 8);
	if (c == 'b')
		return ((color & 0x000000FF) >> 0);
	return (0);
}

int				ft_color(t_init *i, float it, float it_max, char type)
{
	float r;
	float g;
	float b;

	if (type > 0 && type < 8)
		ft_select_color(type, &(i->c->color));
	else if (type == 8)
		i->c->color = ((int)it * i->c->rand) % 0xFFFFFF;
	else
		return (ft_select_bgcolor(type));
	r = (i->c->nega == 0) ?
		((it / it_max) * ft_extract_color('r', i->c->color))
		: (0xFF - ((it / it_max) * ft_extract_color('r', i->c->color)));
	g = (i->c->nega == 0) ?
		((it / it_max) * ft_extract_color('g', i->c->color))
		: (0xFF - ((it / it_max) * ft_extract_color('g', i->c->color)));
	b = (i->c->nega == 0) ?
		((it / it_max) * ft_extract_color('b', i->c->color))
		: (0xFF - ((it / it_max) * ft_extract_color('b', i->c->color)));
	return (ft_get_color((int)r, (int)g, (int)b));
}
