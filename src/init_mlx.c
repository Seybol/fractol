#include "fractol.h"

t_img		*ft_init_img(t_init *i, int length, int heigth)
{
	t_img *a;

	a = (t_img*)malloc(sizeof(t_img));
	a->img = mlx_new_image(i->mlx, length, heigth);
	a->data = mlx_get_data_addr(a->img, &(a->bpp), &(a->sl),
			&(a->endian));
	return (a);
}

int			ft_fractal_number(char *fractal_name)
{
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(fractal_name, "julia") == 0)
		return (2);
	if (ft_strcmp(fractal_name, "ship") == 0)
		return (3);
	if (ft_strcmp(fractal_name, "cactus") == 0)
		return (4);
	if (ft_strcmp(fractal_name, "batman") == 0)
		return (5);
	if (ft_strcmp(fractal_name, "flower") == 0)
		return (6);
	if (ft_strcmp(fractal_name, "snorlax") == 0)
		return (7);
	if (ft_strcmp(fractal_name, "bow") == 0)
		return (8);
	if (ft_strcmp(fractal_name, "tricorn") == 0)
		return (9);
	return (10);
}

t_init		*ft_init_window(char *fractal_name)
{
	t_init *init;

	init = (t_init *)malloc(sizeof(t_init));
	init->mlx = mlx_init();
	init->win = mlx_new_window(init->mlx, WIDTH, HEIGHT, "FRACTOL");
	init->m = ft_init_movements();
	init->fractal = ft_fractal_number(fractal_name);
	init->info = 0;
	init->color = 0;
	init->img = ft_init_img(init, WIDTH, HEIGHT);
	init->c = ft_init_colors();
	init->img_info = ft_init_img_info(init);
	init->img_color = ft_init_img_color(init);
	init->img_it = ft_init_img_it(init);
	return (init);
}

t_color		*ft_init_colors(void)
{
	t_color *c;

	c = (t_color *)malloc(sizeof(t_color));
	c->type = 1;
	c->nega = 0;
	c->color = 0xFFFFFF;
	c->bg_color = 15;
	c->color_type = 0;
	c->rand = 0xF4;
	return (c);
}
