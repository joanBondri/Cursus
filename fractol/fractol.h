#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "printf/Includes/printf.h"
# define MANDELBROT 1
# define JULIA 2

typedef struct	s_comp
{
	double	r;
	double	i;
}				t_comp;

typedef struct	s_fractol
{
	int		set;
	int		width;
	int		height;
	t_comp	base;
}				t_fractol;
#endif
