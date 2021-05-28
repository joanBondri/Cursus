#include <math.h>
#include "fractol.h"

double	norm(t_comp num)
{
	return (sqrt(pow(num.r, 2) + pow(num.i, 2)));
}

int		time_loop_mandelbrot(int time, t_comp num, t_comp c)
{
	t_comp	new;

	if (norm(num) > 2 || time == 0)
        return (time);
    new.r = pow(num.r, 2) - pow(num.i, 2) + c.r;
	new.i = 2 * num.r * num.i + c.i;
	return (time_loop(time - 1, new, c));
}

