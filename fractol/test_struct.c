#include "fractol.h"

void	assign(t_fractol *s)
{

}

int main(void)
{
	t_fractol	s;
	assign(&s);
	s = (t_fractol){.width = 23, .height = 23, .set = 122};
	s = (t_fractol){};
	printf("w = %i, h = %i, set = %i\n", s.width, s.height, s.set);
	return 0;
}
