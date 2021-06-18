#include "fractol.h"

t_comp	get_base_num(char ***arv)
{
	t_comp		res;

	if (++(*arv) && !ft_loop_strchr("0123456789.+-", **arv))
		print_error_text();
	res.r = ft_atod(**arv);
	if (++(*arv) && !ft_loop_strchr("0123456789.+-", **arv))
		print_error_text();
	res.i = ft_atod(**arv);
	return (res);
}

void	check_value(t_fractol unique)
{
	if (unique.width <= 0 || unique.height <= 0
		|| unique.loop < 0 || unique.set == 0)
		print_error_text();
}

void	parse_3(char ***arv, t_fractol *unique)
{
	if (!*(++*arv)
		|| (ft_strncmp("M", **(arv), 3) && ft_strncmp("J", **(arv), 3)))
		print_error_text();
	if (***(arv) == 'M')
		unique->set = MANDELBROT;
	else if (***(arv) == 'J')
	{
		unique->set = JULIA;
		unique->base = get_base_num(arv);
	}
}

void	parse_2(char ***arv, t_fractol *unique)
{
	char	**s;
	char	**f;

	s = (++*arv);
	f = (++*arv);
	if (!*s || !*f)
		print_error_text();
	if (!ft_loop_strchr("0123456789.", *s)
		|| !ft_loop_strchr("0123456789.", *f))
		print_error_text();
	(*unique).width = ft_atoi(*s);
	(*unique).height = ft_atoi(*f);
}

void	parse(char **arv, t_fractol *unique)
{
	while (true)
	{
		if (!*(++arv))
			break ;
		else if (!ft_strncmp("-d", *arv, 3)
			|| !ft_strncmp("--display", *arv, 10))
			parse_2(&arv, unique);
		else if ((!ft_strncmp("-l", *arv, 3) || !ft_strncmp("--loop", *arv, 7))
			&& ft_loop_strchr("0123456789.", *(++arv)))
			unique->loop = ft_atoi(*arv);
		else if (!ft_strncmp("-s", *arv, 3) || !ft_strncmp("--set", *arv, 6))
			parse_3(&arv, unique);
		else
			print_error_text();
	}
	check_value(*unique);
}
