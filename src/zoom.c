#include "defines.h"
#include "struct.h"

void	zoom(t_param *f, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIN_HEGHT ) * (f->end_x - f->start_x)) + f->start_x;
	yy = ((y / WIN_WIDTH) * (f->end_y - f->start_y)) + f->start_y;
	f->start_x = xx + ((f->start_x - xx) * zoom);
	f->start_y = yy + ((f->start_y - yy) * zoom);
	f->end_y = yy + ((f->end_y - yy) * zoom);
	f->end_x = xx + ((f->end_x - xx) * zoom);
	if (f->max <= 120)
		f->max += 2;
}