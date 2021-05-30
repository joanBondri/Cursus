#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol	unique;

	unique = (t_fractol){};
	(void)argc;
	parse(argv, &unique);
	go_to_mlx(&unique, loop);
	return (0);
}
