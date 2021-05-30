#include "fractol.h"

void	print_error_text(void)
{
	int		fd;
	char	*s;

	s = NULL;
	fd = open("error.txt", O_RDWR);
	ft_putendl_fd("\033[0;31mError\033[0m with parameter", 0);
	while (get_next_line(fd, &s) == 1)
	{
		ft_putendl_fd(s, 0);
		free(s);
		s = NULL;
	}
	free(s);
	exit(0);
}

t_comp		get_base_num(char ***arv)
{
	t_comp		res;

	if (++(*arv) && !ft_loop_strchr("0123456789.", **arv))
		print_error_text();
	res.r = ft_atod(**arv);
	if (++(*arv) && !ft_loop_strchr("0123456789.", **arv))
		print_error_text();
	res.i = ft_atod(**arv);
	return (res);
}

void	check_value(t_fractol unique)
{
	if (unique.width <= 0 || unique.height <= 0 ||
			unique.loop < 0 || unique.set == 0)
		print_error_text();
}

void	parse(char **arv, t_fractol *unique)
{
	char	**s;
	char	**f;

	while (true)
	{
		s = (++arv);
		if (!*s)
			break ;
		if (!ft_strncmp("-s", *s, 3) || !ft_strncmp("--set", *s, 6))
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
		else if (!ft_strncmp("-d", *s, 3) || !ft_strncmp("--display", *s, 10))
		{
			s = (++arv);
			f = (++arv);
			if (!*s || !*f)
				print_error_text();
			if (!ft_loop_strchr("0123456789.", *s) ||
					!ft_loop_strchr("0123456789.", *f))
				print_error_text();
			*unique = (t_fractol){.width = ft_atoi(*s), .height = ft_atoi(*f),
			   	.set = unique->set, .base = unique->base, .loop = unique->loop};
		}
		else if (!ft_strncmp("-l", *s, 3) || !ft_strncmp("--loop", *s, 7))
		{
			if (!ft_loop_strchr("0123456789.", *(++arv)))
				print_error_text();
			unique->loop = ft_atoi(*arv);
		}
		else
			print_error_text();
	}
	check_value(*unique);
}
