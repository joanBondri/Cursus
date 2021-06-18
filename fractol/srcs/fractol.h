#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <limits.h>
# include "libft.h"
# define ESC 65307
# define COLOR_MAX 16777215
# define SHORT_MAX 65535
# define BASIC_LOOP 500
# define MANDELBROT 1
# define JULIA 2
# define KEY_ZOOM 5
# define KEY_UNZOOM 4

typedef union u_color
{
	int		result;
	short	i;
	char	c[2];
}				t_color;

typedef struct s_comp
{
	double	r;
	double	i;
}				t_comp;

typedef struct s_fractol
{
	int		set;
	int		width;
	int		height;
	t_comp	base;
	int		loop;
	t_comp	center;
	double	scale;
}				t_fractol;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_store
{
	t_mlx			mlx;
	t_img			img;
	t_fractol		frct;
}					t_store;

void	go_to_mlx(t_fractol *unique);
void	parse(char **arv, t_fractol *unique);
void	print_error_text(void);
int		time_loop(int time, t_comp num, t_comp c);
int		next_frame(t_store *s);
float	norm(t_comp num);
int		hsv_to_hex(double h, float s, float v);
int		time_loop_julia(int time, t_comp num, t_comp c);
int		mouse_event(int button, int x, int y, t_store *s);
t_comp	find_dot_coo(int i, int j, t_fractol u);

#endif
