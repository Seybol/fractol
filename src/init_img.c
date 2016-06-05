#include "fractol.h"

t_img	*ft_init_img_info(t_init *i)
{
	int		k;
	int		j;
	t_img	*img_info;

	k = 800;
	j = 100;
	img_info = (t_img*)malloc(sizeof(t_img));
	img_info->img = mlx_xpm_file_to_image(i->mlx, "./xpm/info.XPM", &k, &j);
	img_info->data = mlx_get_data_addr(img_info->img, &(img_info->bpp),
			&(img_info->sl), &(img_info->endian));
	return (img_info);
}

t_img	*ft_init_img_color(t_init *i)
{
	int		k;
	int		j;
	t_img	*img_info;

	k = 100;
	j = 600;
	img_info = (t_img*)malloc(sizeof(t_img));
	img_info->img = mlx_xpm_file_to_image(i->mlx, "./xpm/colors.XPM", &k, &j);
	img_info->data = mlx_get_data_addr(img_info->img,
			&(img_info->bpp), &(img_info->sl),
				&(img_info->endian));
	return (img_info);
}

t_img	*ft_init_img_it(t_init *i)
{
	float k;
	float j;
	t_img *img_info;

	img_info = ft_init_img(i, WIDTH, 30);
	k = 0;
	j = 0;
	while (j < 30)
	{
		while (k < WIDTH)
		{
			putpixel(k, j, 0, img_info);
			k++;
		}
		k = 0;
		j++;
	}
	return (img_info);
}
