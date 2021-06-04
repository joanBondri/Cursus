#include "fractol.h"

t_comp		find_dot_coo(int i, int j, t_fractol u)
{
	t_comp	res;

	res.r = 2 * i * u.scale / u.width - u.scale + u.center.r;
	res.i = (u.height - 2 * j) * u.scale / u.width + u.center.i;
	return res;
}

char		func_one(char c)
{
	return ((c * 7 + 42) % 256);
}

char		func_two(char c)
{
	return ((c) % 256);
}

void	get_color_with_score(char *d, char *g, int time)
{
	char	swp;
	swp = *d;
	*d = *g;
	if (time % 2 == 0)
		*g = func_one(*g) ^ swp;
	else
		*g = func_two(*g) ^ swp;
	if (--time != 0)
		get_color_with_score(d, g, time);
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
	t_comp	coo;
	t_color	result;
	float	conv;

	i = -1;
	j = -1;
	while (++i < s->frct.width)
	{
		j = -1;
		while (++j < s->frct.height)
		{
			coo = find_dot_coo(i, j, s->frct);
			if (s->frct.set == JULIA)
			{
				result.result = time_loop_julia(s->frct.loop, coo, s->frct.base);
				my_mlx_pixel_put(s->img, i, j, result.result);
				continue ;
			}
			else if (s->frct.set == MANDELBROT)
				result.result = time_loop(s->frct.loop, (t_comp){}, coo);
			get_color_with_score(result.c, result.c + 1, 4);
			conv = (float)result.result;
			result.result = (int)(conv / SHORT_MAX * COLOR_MAX);
			my_mlx_pixel_put(s->img, i, j, result.result);
		}
	}
}
