#include "fractol.h"

int			ft_mouse(int button, int x, int y, void *param)
{
	t_init *i;

	i = (t_init *)param;
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_BOTTOM)
		ft_zoom_in(i);
	if (button == MOUSE_WHEEL_UP)
		ft_zoom_out(i);
	ft_draw_fractal(i);
	return (1);
}

void		ft_zoom_in(t_init *i)
{
	i->m->x += (i->m->mx - WIDTH / 2) / (i->m->scale * WIDTH / 2);
	i->m->y += (i->m->my - HEIGHT / 2) / (i->m->scale * HEIGHT / 2);
	i->m->scale = (i->m->scale > 3500000000000000000) ? i->m->scale
		: (i->m->scale * 1.4);
	i->m->x -= (i->m->mx - WIDTH / 2) / (i->m->scale * WIDTH / 2);
	i->m->y -= (i->m->my - HEIGHT / 2) / (i->m->scale * HEIGHT / 2);
}

void		ft_zoom_out(t_init *i)
{
	i->m->x += (i->m->mx - WIDTH / 2) / (i->m->scale * WIDTH / 2);
	i->m->y += (i->m->my - HEIGHT / 2) / (i->m->scale * HEIGHT / 2);
	i->m->scale = (i->m->scale < 0.1) ? i->m->scale : (i->m->scale * 0.6);
	i->m->x -= (i->m->mx - WIDTH / 2) / (i->m->scale * WIDTH / 2);
	i->m->y -= (i->m->my - HEIGHT / 2) / (i->m->scale * HEIGHT / 2);
}
