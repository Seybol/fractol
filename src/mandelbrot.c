#include "fractol.h"

int		ft_mandelbrot(t_init *i, t_fract_var *f)
{
	int		it;
	double	zr;
	double	zim;

	it = -1;
	zr = f->z_r * f->z_r;
	zim = f->z_im * f->z_im;
	while ((zr + zim) < 4 && ++it < i->m->it_max)
	{
		f->z_im *= f->z_r;
		f->z_im += f->z_im;
		f->z_im += f->c_im;
		f->z_r = zr - zim + f->c_r;
		zr = f->z_r * f->z_r;
		zim = f->z_im * f->z_im;
	}
	if (it == i->m->it_max)
		putpixel(f->x, f->y, ft_color(i, 0, 0, i->c->bg_color), i->img);
	else
		putpixel(f->x, f->y, ft_color(i, it, i->m->it_max, i->c->type),
				i->img);
	return (it);
}
