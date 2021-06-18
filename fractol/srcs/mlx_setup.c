#include "fractol.h"

void	resize(void *mlx, t_fractol *u)
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

int	windows_key(t_store *s)
{
	mlx_destroy_image(s->mlx.mlx, s->img.img);
	mlx_destroy_window(s->mlx.mlx, s->mlx.mlx_win);
	exit(0);
	return (0);
}

int	escape(int keycode, t_store *s)
{
	(void)s;
	if (keycode == ESC)
		windows_key(s);
	return (0);
}

void	main_mlx(t_store *s)
{
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.mlx_win, s->img.img, 0, 0);
	mlx_hook(s->mlx.mlx_win, 4, 1 << 2, &mouse_event, s);
	mlx_key_hook(s->mlx.mlx_win, escape, s);
	mlx_expose_hook(s->mlx.mlx_win, next_frame, s);
	mlx_hook(s->mlx.mlx_win, 33, 1L << 17, windows_key, s);
	mlx_loop(s->mlx.mlx);
}

void	go_to_mlx(t_fractol *unique)
{
	t_mlx	mlx;
	t_img	img;
	t_store	s;

	mlx.mlx = mlx_init();
	resize(mlx.mlx, unique);
	mlx.mlx_win = mlx_new_window(mlx.mlx, unique->width,
			unique->height, "Fractol");
	img.img = mlx_new_image(mlx.mlx, unique->width, unique->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	s.mlx = mlx;
	s.img = img;
	s.frct = *unique;
	main_mlx(&s);
}
