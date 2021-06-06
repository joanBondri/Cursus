#include "fractol.h"

int mouse_event(int button, int x, int y, t_store *s)
{
	if (button != KEY_ZOOM && button != KEY_UNZOOM)
		return (0);
	s->frct.center = find_dot_coo(x, y, s->frct);
	if (button == KEY_ZOOM)
		s->frct.scale *= 0.6;
	if (button == KEY_UNZOOM)
		s->frct.scale *= 1.4;
	next_frame(s);
	return 0;
}
