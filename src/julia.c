#include "fractol.h"

int		ft_julia(t_init *i, t_fract_var *f)
{
	int it;

	it = 0;
	f->z_r = (f->x - WIDTH / 2) / (i->m->scale * WIDTH / 2) + i->m->x;
	f->z_im = (f->y - HEIGHT / 2) / (i->m->scale * HEIGHT / 2) + i->m->y;
	f->c_r = (i->m->jx - WIDTH / 2) / (0.5 * WIDTH / 2);
	f->c_im = (i->m->jy - HEIGHT / 2) / (0.5 * HEIGHT / 2);
	while (f->z_r * f->z_r + f->z_im * f->z_im < 4 && it < i->m->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_im * f->z_im + f->c_r;
		f->z_im = 2 * f->tmp * f->z_im + f->c_im;
		++it;
	}
	if (it == i->m->it_max)
		putpixel(f->x, f->y, ft_color(i, 0, 0, i->c->bg_color), i->img);
	else
		putpixel(f->x, f->y, ft_color(i, it, i->m->it_max, i->c->type),
				i->img);
	return (it);
}
