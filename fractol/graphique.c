#include "fractol.h"

t_comp	find_dot_coo(int i, int j, t_fractol u)
{
	t_comp	res;

	res.r = 2 * i * u.scale / u.width - u.scale + u.center.r;
	res.i = (u.height - 2 * j) * u.scale / u.width + u.center.i;
	return (res);
}

void	my_mlx_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	(void)color;
	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	next_frame(t_store *s)
{
	int			i;
	int			j;
	t_comp		coo;
	t_color		result;
	t_fractol	u;

	i = -1;
	j = -1;
	u = s->frct;
	while (++i < u.width)
	{
		j = -1;
		while (++j < u.height)
		{
			coo.r = 2 * i * u.scale / u.width - u.scale + u.center.r;
			coo.i = (u.height - 2 * j) * u.scale / u.width + u.center.i;
			if (u.set == JULIA)
				result.result = time_loop_julia(u.loop, coo, u.base);
			else if (u.set == MANDELBROT)
				result.result = time_loop_julia(u.loop, (t_comp){}, coo);
			my_mlx_pixel_put(s->img, i, j, result.result);
		}
	}
	mlx_put_image_to_window(s->mlx.mlx,
		s->mlx.mlx_win, s->img.img, 0, 0);
}
