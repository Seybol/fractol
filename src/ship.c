#include "fractol.h"
#include <math.h>

int		ft_ship(t_init *i, t_fract_var *f)
{
	int it;

	it = 0;
	f->c_r = (f->x - WIDTH / 2) / (i->m->scale * WIDTH / 2) + i->m->x;
	f->c_im = (f->y - HEIGHT / 2) / (i->m->scale * HEIGHT / 2) + i->m->y;
	f->z_r = 0;
	f->z_im = 0;
	while (f->z_r * f->z_r + f->z_im * f->z_im < 4 && it < i->m->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_im * f->z_im - f->c_r;
		f->z_im = 2 * fabs(f->tmp) * fabs(f->z_im) + f->c_im;
		++it;
	}
	if (it == i->m->it_max)
		putpixel(f->x, f->y, ft_color(i, 0, 0, i->c->bg_color), i->img);
	else
		putpixel(f->x, f->y, ft_color(i, it, i->m->it_max, i->c->type), i->img);
	return (it);
}
