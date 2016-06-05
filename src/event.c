#include "fractol.h"

void		ft_keyboard_movement(int keycode, t_init *i)
{
	if (keycode == KEY_RIGHT)
		i->m->x += 0.1 / i->m->scale;
	else if (keycode == KEY_LEFT)
		i->m->x -= 0.1 / i->m->scale;
	else if (keycode == KEY_BOTTOM)
		i->m->y += 0.1 / i->m->scale;
	else if (keycode == KEY_UP)
		i->m->y -= 0.1 / i->m->scale;
	else if (keycode == KEY_R)
		ft_reset_position(i);
	else if (keycode == KEY_A)
		i->m->scale = (i->m->scale > 3500000000000000000) ? i->m->scale
			: (i->m->scale * 1.4);
	else if (keycode == KEY_S)
		i->m->scale = (i->m->scale < 0.1) ? i->m->scale : (i->m->scale * 0.6);
	else if (keycode == KEY_Z)
		ft_zoom_in(i);
	else if (keycode == KEY_X)
		ft_zoom_out(i);
	else if (keycode == KEY_COMMA)
		i->fractal = (i->fractal < 9 && i->fractal >= 1) ? (i->fractal + 1) : 1;
	else if (keycode == KEY_DOT)
		i->fractal = (i->fractal < 10 && i->fractal >= 2) ?
			(i->fractal - 1) : 9;
}

int			ft_keyboard(int keycode, void *init)
{
	t_init *i;

	i = (t_init *)init;
	ft_keyboard_movement(keycode, i);
	if (i->c->color_type == 0)
		ft_choose_color(i, keycode);
	else
		ft_choose_bgcolor(i, keycode);
	if (keycode == KEY_J)
		i->m->toggle_julia = (i->m->toggle_julia == 1) ? 0 : 1;
	else if (keycode == KEY_I)
		i->info = (i->info == 1) ? 0 : 1;
	else if (keycode == KEY_Q)
		i->m->it_max = (i->m->it_max > 0 && i->m->it_max < 1000)
			? ++i->m->it_max : i->m->it_max;
	else if (keycode == KEY_W)
		i->m->it_max = (i->m->it_max > 1) ? --i->m->it_max : i->m->it_max;
	else if (keycode == KEY_V)
		i->c->color_type = (i->c->color_type == 0) ? 1 : 0;
	else if (keycode == KEY_C)
		i->color = (i->color == 0) ? 1 : 0;
	else if (keycode == KEY_ESC)
		ft_close(i);
	ft_draw_fractal(i);
	return (1);
}

void		ft_reset_position(t_init *i)
{
	i->m->scale = 0.5;
	i->m->x = 0;
	i->m->y = 0;
}

void		ft_choose_color(t_init *i, int keycode)
{
	if (keycode == KEY_1)
		i->c->type = 1;
	else if (keycode == KEY_2)
		i->c->type = 2;
	else if (keycode == KEY_3)
		i->c->type = 3;
	else if (keycode == KEY_4)
		i->c->type = 4;
	else if (keycode == KEY_5)
		i->c->type = 5;
	else if (keycode == KEY_6)
		i->c->type = 6;
	else if (keycode == KEY_7)
		i->c->type = 7;
	else if (keycode == KEY_9)
		i->c->type = 8;
	else if (keycode == KEY_8)
		i->c->type = 16;
	else if (keycode == KEY_TILT)
		i->c->nega = (i->c->nega == 0) ? 1 : 0;
	else if (keycode == KEY_0)
		i->c->rand *= 0xFF;
}

void		ft_choose_bgcolor(t_init *i, int keycode)
{
	if (keycode == KEY_1)
		i->c->bg_color = 15;
	else if (keycode == KEY_2)
		i->c->bg_color = 9;
	else if (keycode == KEY_3)
		i->c->bg_color = 10;
	else if (keycode == KEY_4)
		i->c->bg_color = 11;
	else if (keycode == KEY_5)
		i->c->bg_color = 12;
	else if (keycode == KEY_6)
		i->c->bg_color = 13;
	else if (keycode == KEY_7)
		i->c->bg_color = 14;
	else if (keycode == KEY_8)
		i->c->bg_color = 17;
}
