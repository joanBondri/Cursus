#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "printf/Includes/printf.h"
# include <mlx.h>
# include <limits.h>
# define COLOR_MAX 16777215
# define SHORT_MAX 65535
# define BASIC_LOOP 500
# define MANDELBROT 1
# define JULIA 2

typedef union	u_color
{
	int		result;
	short	i;
	char	c[2];
}				t_color;

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
	int		loop;
	t_comp	center;
	double	scale;
}				t_fractol;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

typedef	struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef	struct		s_store
{
	t_mlx			mlx;
	t_img			img;
	t_fractol		frct;
}					t_store;

void	go_to_mlx(t_fractol *unique);
void	parse(char **arv, t_fractol *unique);
void	print_error_text(void);
int		time_loop(int time, t_comp num, t_comp c);
void	next_frame(t_store *s);

#endif
