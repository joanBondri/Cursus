#include "fractol.h"

int mouse_event(int button, int x, int y, t_store *s)
{
	printf("keycode = %i x = %i, y = %i, p = %p\n", button, x, y, s);	
	return 0;
}
