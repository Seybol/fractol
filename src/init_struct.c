#include "fractol.h"

t_move		*ft_init_movements(void)
{
	t_move *m;

	m = (t_move*)malloc(sizeof(t_move));
	m->scale = 0.5;
	m->x = 0;
	m->y = 0;
	m->it_max = 10;
	m->mx = 0;
	m->my = 0;
	m->toggle_julia = 1;
	m->jx = 0;
	m->jy = 0;
	return (m);
}

t_fract_var	*ft_init_fract_var(void)
{
	t_fract_var *f;

	f = (t_fract_var *)malloc(sizeof(t_fract_var));
	f->x = 0;
	f->y = 0;
	f->tmp = 0;
	return (f);
}

void		ft_init_complex(t_fract_var *f, t_init *l)
{
	f->c_r = (f->x - WIDTH / 2) / (l->m->scale *
			WIDTH / 2) + l->m->x;
	f->c_im = (f->y - HEIGHT / 2) / (l->m->scale * HEIGHT / 2) + l->m->y;
	f->z_r = 0;
	f->z_im = 0;
}
