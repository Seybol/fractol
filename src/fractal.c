#include "fractol.h"

static int	ft_calculate_iteration(t_init *i, t_fract_var *f)
{
	if (i->fractal == 1)
	{
		ft_init_complex(f, i);
		return (ft_mandelbrot(i, f));
	}
	if (i->fractal == 2)
		return (ft_julia(i, f));
	if (i->fractal == 3)
		return (ft_ship(i, f));
	if (i->fractal == 4)
		return (ft_cactus(i, f));
	if (i->fractal == 5)
		return (ft_batman(i, f));
	if (i->fractal == 6)
		return (ft_flower(i, f));
	if (i->fractal == 7)
		return (ft_snorlax(i, f));
	if (i->fractal == 8)
		return (ft_bow(i, f));
	if (i->fractal == 9)
		return (ft_tricorn(i, f));
	return (-1);
}

static void	*calculate(void *arg)
{
	t_fract_var		*f;
	t_thread		*t;
	int				len;
	t_init			*l;

	t = (t_thread *)arg;
	l = (t_init *)t->i;
	len = t->threads * WIDTH / 8;
	f = ft_init_fract_var();
	f->x = (t->threads - 1) * WIDTH / 8;
	while (f->x < len)
	{
		while (f->y < HEIGHT)
		{
			ft_calculate_iteration(t->i, f);
			++f->y;
		}
		f->y = 0;
		++f->x;
	}
	free(f);
	pthread_exit(0);
}

static void	ft_put_image_color(t_init *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->img_color->img, 0, 0);
	if (l->c->color_type)
	{
		mlx_string_put(l->mlx, l->win, 4, 20, 0x404040, "Primary");
		mlx_string_put(l->mlx, l->win, 4, 50, 0xFF4040, "Secondary");
	}
	else if (l->c->color_type == 0)
	{
		mlx_string_put(l->mlx, l->win, 4, 20, 0xFF4040, "Primary");
		mlx_string_put(l->mlx, l->win, 4, 50, 0x404040, "Secondary");
	}
}

static void	ft_put_image_it(t_init *l)
{
	mlx_put_image_to_window(l->mlx, l->win, l->img_it->img, 0, HEIGHT - 30);
	mlx_string_put(l->mlx, l->win, 10, HEIGHT - 29, 0xFFFFFF, "Iterations : ");
	mlx_string_put(l->mlx, l->win, 150, HEIGHT - 29, 0xFFFFFF,
			ft_itoa(l->m->it_max));
	mlx_string_put(l->mlx, l->win, 200, HEIGHT - 29, 0xFFFFFF, "Zoom :   x");
	mlx_string_put(l->mlx, l->win, 300, HEIGHT - 29, 0xFFFFFF,
			ft_itoa_size_t((size_t)l->m->scale));
	mlx_string_put(l->mlx, l->win, WIDTH - 300, HEIGHT - 29, 0xFFFFFF,
			"Press I for more informations");
}

void		***ft_draw_fractal(t_init *l)
{
	int			i;

	i = 0;
	while (i < 8)
	{
		l->th[i].threads = i + 1;
		l->th[i].i = (t_init *)l;
		pthread_create(&l->th[i].t, NULL, calculate, &l->th[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(l->th[i].t, NULL);
		i++;
	}
	mlx_put_image_to_window(l->mlx, l->win, l->img->img, 0, 0);
	if (l->info)
		mlx_put_image_to_window(l->mlx, l->win, l->img_info->img, 0, 0);
	if (l->color)
		ft_put_image_color(l);
	ft_put_image_it(l);
	return (NULL);
}
