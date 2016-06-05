#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include <pthread.h>
# define WIDTH 800
# define HEIGHT 800

typedef struct	s_move
{
	double		scale;
	double		x;
	double		y;
	short		mx;
	short		my;
	short		jx;
	short		jy;
	int			it_max;
	char		toggle_julia;
}				t_move;

typedef struct	s_fract_var
{
	short		x;
	short		y;
	double		c_r;
	double		c_im;
	double		z_r;
	double		z_im;
	double		tmp;
}				t_fract_var;

typedef struct	s_img
{
	char		*data;
	int			sl;
	int			endian;
	int			bpp;
	void		*img;
}				t_img;

typedef struct	s_color
{
	char		type;
	char		nega;
	int			color;
	int			bg_color;
	int			color_type;
	int			rand;
}				t_color;

typedef struct	s_thread
{
	int			threads;
	pthread_t	t;
	void		*i;
}				t_thread;

typedef struct	s_init
{
	char		*data;
	void		*mlx;
	void		*win;
	t_move		*m;
	t_img		*img;
	t_img		*img_info;
	t_img		*img_color;
	t_img		*img_it;
	int			fractal;
	char		*fractal_name;
	char		info;
	char		color;
	t_color		*c;
	t_thread	th[8];
}				t_init;

t_init			*ft_init_window(char *fractal_name);
int				ft_keyboard(int keycode, void *init);
int				ft_mouse(int button, int x, int y, void *param);
void			ft_close(t_init *i);
void			putpixel(int x, int y, unsigned int color, t_img *img);
void			***ft_draw_fractal(t_init *l);
int				ft_mandelbrot(t_init *i, t_fract_var *f);
int				ft_julia(t_init *i, t_fract_var *f);
int				ft_ship(t_init *i, t_fract_var *f);
int				ft_cactus(t_init *i, t_fract_var *f);
t_img			*ft_init_img(t_init *i, int length, int heigth);
t_move			*ft_init_movements(void);
t_img			*ft_init_img(t_init *i, int length, int heigth);
t_init			*ft_init_window(char *fractal_name);
t_fract_var		*ft_init_fract_var(void);
void			ft_zoom_in(t_init *i);
void			ft_zoom_out(t_init *i);
void			ft_reset_position(t_init *i);
void			ft_init_complex(t_fract_var *f, t_init *l);
int				ft_color(t_init *i, float it, float it_max, char type);
t_img			*ft_init_img_color(t_init *i);
t_color			*ft_init_colors(void);
t_img			*ft_init_img_it(t_init *i);
char			*ft_itoa_size_t(size_t n);
void			ft_choose_color(t_init *i, int keycode);
void			ft_choose_bgcolor(t_init *i, int keycode);
t_img			*ft_init_img_info(t_init *i);
int				ft_tricorn(t_init *i, t_fract_var *f);
int				ft_flower(t_init *i, t_fract_var *f);
int				ft_batman(t_init *i, t_fract_var *f);
int				ft_snorlax(t_init *i, t_fract_var *f);
int				ft_bow(t_init *i, t_fract_var *f);
#endif
