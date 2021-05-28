#include "fractol.h"

void		parse(int arc, char **arv, t_fractol *unique)
{
	char	*s;
	char	*f;

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
				*unique = (t_fractol){.width = ft_atoi(s), .height = ft_atoi(f),
			   		.set = unique->set, .base = unique->base};
			{
				unique->set = JULIA;
			}
		}
		else if (!ft_strncmp("-d", s, 3) || !ft_strncmp("--display", s, 10))
		{
			s = *(++arv);
			f = *(++arv);
			if (error_parse_display(s, f))
				print_error_text();
			*unique = (t_fractol){.width = ft_atoi(s), .height = ft_atoi(f),
			   	.set = unique->set, .base = unique->base};
		}
		else if (!ft_strncmp("-l", s, 3) || !ft_strncmp("--loop", s, 7))
		{

		}
	}
}
