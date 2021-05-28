#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol	unique;

	unique = (t_fractol){};
	parse(argc, argv, &unique);
	return (0);
}
