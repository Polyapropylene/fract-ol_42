#include "fractol.h"

int	decide_colour(int iter)
{
	t_colour	colour;

	colour.r = iter * 100 / ITER_MAX + 200;
	colour.g = iter * 90 - 40;
	colour.b = (iter + 500) * 100 / ITER_MAX;
	return ((colour.r << 16) + (colour.g << 8) + colour.b);
}