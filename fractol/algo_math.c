#include "fractol.h"

float	norm(t_comp num)
{
	return ((float)sqrt(pow(num.r, 2) + pow(num.i, 2)));
}

/*int		time_loop(int time, t_comp num, t_comp c)
{
	t_comp	new;

	if (norm(num) > 2 || time == 0)
        return (time);
    new.r = pow(num.r, 2) - pow(num.i, 2) + c.r;
	new.i = 2 * num.r * num.i + c.i;
	return (time_loop(time - 1, new, c));
}*/

int			time_loop(int time, t_comp num, t_comp c)
{
	t_comp		new;

	time++;
	while (--time > 0 && norm(num) < 10)
	{
    	new.r = pow(num.r, 2) - pow(num.i, 2) + c.r;
		new.i = 2 * num.r * num.i + c.i;
	 	num = new;
	}
	return (time);
}

int			time_loop_julia(int time, t_comp num, t_comp c)
{
	t_comp		new;
	double		smooth;

	time++;
	smooth = exp(-1 * sqrt(num.r * num.r + num.i * num.i));
	while (--time > 0 && sqrt(num.r * num.r + num.i * num.i) < 10)
	{
    	new.r = num.r * num.r - num.i * num.i + c.r;
		new.i = 2 * num.r * num.i + c.i;
	 	num = new;
		smooth += exp(-1 * sqrt(num.r * num.r + num.i * num.i));
	}
	if (sqrt(num.r * num.r + num.i * num.i) < 2)
		return (0);
	return (hsv_to_hex(smooth, 0.9, 0.8));
}
