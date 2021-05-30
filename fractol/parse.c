#include "fractol.h"

double			ft_atoi_f(char *str)
{
	double	res;
	char	*dot_str;
	int		sign;

	sign = 1;
	dot_str = str;
	if (*dot_str == '-' || *dot_str == '+')
	{
		if (*dot_str == '-')
			sign = -1;
		dot_str++;
	}
	res = (double)ft_atoi(dot_str);
	if (res < 0)
		return (0.0);
	dot_str = afterset(dot_str, "0123456789");
	if (dot_str[0] != '.')
		return (sign * res);
	return (sign * (res + decimal(dot_str)));
}

t_comp		get_base_num(char ***arv)
{
	t_comp		res;
	float		real;
	float		image;

	if (ft_loop_strchr("0123456789.", *(++*arv)))
		print_error_text();
	res.r = ft_atof(**arv);
	if (ft_loop_strchr("0123456789.", *(++*arv)))
		print_error_text();
	res.i = ft_atof(**arv);
	return (res);
}

int		parse(int arc, char **arv, t_fractol *unique)
{
	char	**s;
	char	**f;
	int		res;

	while (true)
	{
		s = *(++arv);
		if (!s)
			break ;
		if (!ft_strncmp("-s", s, 3) || !ft_strncmp("--set", s, 6))
		{
			if (!*(++arv) ||
					(ft_strncmp("M", *(arv), 3) && ft_strncmp("J", *(arv), 3)))
				print_error_text();
			if (**(arv) == 'M')
				unique->set = MANDELBROT;
			else if (**(arv) == 'J')
			{
				unique->set = JULIA;
				unique->base = get_base_num(&arv);
			}
		}
		else if (!ft_strncmp("-d", s, 3) || !ft_strncmp("--display", s, 10))
		{
			s = (++arv);
			f = (++arv);
			if (!*s || !*f)
				print_error_text();
			if (ft_is_float(*s) || ft_is_float(*f))
				print_error_text();
			*unique = (t_fractol){.width = ft_atoi(s), .height = ft_atoi(f),
			   	.set = unique->set, .base = unique->base};
		}
		else if (!ft_strncmp("-l", s, 3) || !ft_strncmp("--loop", s, 7))
		{
			if (ft_loop_strchr("0123456789.", *(++arv)))
				print_error_text();
			res = ft_atoi(*arv);
		}
	}
	return (res);
}
