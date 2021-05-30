#include "fractol.h"

void		resize(void *mlx, t_fractol *u)
{
	int		x;
	int		y;

	mlx_get_screen_size(mlx, &x, &y);
	if (u->width > x || u->width == 0)
		u->width = x;
	if (u->height > y || u->height == 0)
		u->height = y;
	if (u->loop == 0)
		u->loop = 500;
	return ;
}

void		my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	(void)color;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		next_frame(t_store *s)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->frct.width)
	{
		j = -1;
		while (++j < s->frct.height)
			my_mlx_pixel_put(s->img, i, j, 50000);
	}
}

int			minimalize(t_store *s)
{
	next_frame(s);
	mlx_put_image_to_window(s->mlx.mlx,
			s->mlx.mlx_win, s->img.img, 0, 0);
	return (0);
}

void		main_mlx(t_store *s)
{
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, 0, 0);
	//mlx_mouse_hook(s->mlx.mlx_win, clic_image, s);
//	mlx_key_hook(s->mlx.mlx_win, move_sth, s);
//	mlx_hook(s->mlx.mlx_win, 33, 1L << 17, windows_key, s);
	mlx_expose_hook(s->mlx.mlx_win, minimalize, s);
	mlx_loop(s->mlx.mlx);
}


void	go_to_mlx(t_fractol *unique)
{
	t_mlx	mlx;
	t_img	img;
	t_store	s;

	mlx.mlx = mlx_init();
	resize(mlx.mlx, unique);
	mlx.mlx_win = mlx_new_window(mlx.mlx, unique->width, unique->height, "Fractol");
	img.img = mlx_new_image(mlx.mlx, unique->width, unique->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	s.mlx = mlx;
	s.img = img;
	s.frct = *unique;
	main_mlx(&s);
}
