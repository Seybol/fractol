#include "fractol.h"

int		ft_mouse_julia(int x, int y, void *param)
{
	t_init *i;

	i = (t_init *)param;
	if (i->m->toggle_julia)
	{
		i->m->jx = x;
		i->m->jy = y;
		ft_draw_fractal(i);
	}
	i->m->mx = x;
	i->m->my = y;
	return (1);
}

void	ft_show_error(void)
{
	ft_putstr("Error ! Please try again with following arguments :\n");
	ft_putstr("-> mandelbrot\n");
	ft_putstr("-> julia\n");
	ft_putstr("-> ship\n");
	ft_putstr("-> cactus\n");
	ft_putstr("-> batman\n");
	ft_putstr("-> flower\n");
	ft_putstr("-> snorlax\n");
	ft_putstr("-> bow\n");
	ft_putstr("-> tricorn\n");
	exit(0);
}

void	ft_error_handling(int argc, char **argv)
{
	if (argc != 2)
		ft_show_error();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return ;
	else if (ft_strcmp(argv[1], "julia") == 0)
		return ;
	else if (ft_strcmp(argv[1], "cactus") == 0)
		return ;
	else if (ft_strcmp(argv[1], "ship") == 0)
		return ;
	else if (ft_strcmp(argv[1], "batman") == 0)
		return ;
	else if (ft_strcmp(argv[1], "flower") == 0)
		return ;
	else if (ft_strcmp(argv[1], "snorlax") == 0)
		return ;
	else if (ft_strcmp(argv[1], "bow") == 0)
		return ;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		return ;
	ft_show_error();
}

void	ft_close(t_init *i)
{
	mlx_destroy_image(i->mlx, i->img->img);
	mlx_destroy_image(i->mlx, i->img_info->img);
	mlx_destroy_image(i->mlx, i->img_color->img);
	mlx_destroy_image(i->mlx, i->img_it->img);
	mlx_destroy_window(i->mlx, i->win);
	free(i->img);
	free(i->img_info);
	free(i->img_color);
	free(i->img_it);
	free(i->c);
	free(i);
	i = NULL;
	ft_putstr("Program closed successfully.\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_init *init;

	ft_error_handling(argc, argv);
	init = ft_init_window(argv[1]);
	ft_draw_fractal(init);
	mlx_mouse_hook(init->win, ft_mouse, init);
	mlx_do_key_autorepeaton(init->mlx);
	//mlx_loop_hook(init->mlx, &noevent, init);
	mlx_hook(init->win, 2, 0L, ft_keyboard, init);
	mlx_hook(init->win, 6, 1, ft_mouse_julia, init);
	mlx_loop(init->mlx);
	return (0);
}
