#include "fractol.h"

int	ft_flower(t_init *i, t_fract_var *f)
{
	int it;

	it = 0;
	ft_init_complex(f, i);
	while (f->z_r * f->z_r + f->z_im * f->z_im <= 4 && it <= i->m->it_max)
	{
		f->tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_im * f->z_im + f->c_r - f->z_r;
		f->z_im = 2 * f->tmp * f->z_im + f->c_im - f->z_im;
		++it;
	}
	if (it == i->m->it_max)
		putpixel(f->x, f->y, ft_color(i, 0, 0, i->c->bg_color), i->img);
	else
		putpixel(f->x, f->y, ft_color(i, it, i->m->it_max, i->c->type),
				i->img);
	return (it);
}
