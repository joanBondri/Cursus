#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol	unique;

	unique = (t_fractol){};
	(void)argc;
	parse(argv, &unique);
	unique.scale = 2;
	unique.center = (t_comp){.r = 0.0, .i = 0.0};
	go_to_mlx(&unique);
	return (0);
}
