#include "fractol.h"

t_comp		find_dot_coo(int i, int j, t_fractol u)
{
	t_comp	res;

	res.r = 2 * i * u.scale / u.width - u.scale + u.center.r;
	res.i = (u.height - 2 * j) * u.scale / u.width + u.center.i;
	return res;
}

int			get_color_with_score(int score, int loop)
{
	float	res;

	res = (loop - score) / loop;
	res *= 16777215;
	return (int)res;
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
	int		result;
	int		color;

	i = -1;
	j = -1;
	while (++i < s->frct.width)
	{
		j = -1;
		while (++j < s->frct.height)
		{
			coo = find_dot_coo(i, j, s->frct);
			result = time_loop(s->frct.loop, s->frct.base, coo);
			color = get_color_with_score(result, s->frct.loop);
			my_mlx_pixel_put(s->img, i, j, color);
		}
	}
}
