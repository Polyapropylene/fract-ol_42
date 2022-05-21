#include "fractol.h"

int	iter_mandelbrot(t_cmplx *z)
{
	int	iter;
	double	tmp;
	
	iter = 0;
	z->x0 = z->x;
	z->y0 = z->y;
	while (iter < ITER_MAX && (z->x * z->x + z->y * z->y) <= 4)
	{
		tmp = z->x;
		z->x = z->x * z->x - z->y * z->y + z->x0;
		z->y = 2 * tmp * z->y + z->y0;
		iter++;
	}
	if (iter == ITER_MAX)
		return (0x00000000);
	else
		return (decide_colour(iter));
}

/*int	iter_julia(t_cmplx *z)
{
	int	iter;
	
	iter = 0;
	while (iter < ITER_MAX && (z->x * z->x + z->y * z->y) <= 4)
	{
		z->x = z->x * z->x - z->y * z->y + ;
		z->y = ;
		iter++;
	}
	return (iter);
}

int	iter_newton(t_cmplx *z)
{
	int	iter;
	double	tmp;
	
	iter = 0;
	z->x0 = z->x;
	z->y0 = z->y;
	while (iter < ITER_MAX && (z->x * z->x + z->y * z->y) <= 4)
	{
	
		iter++;
	}
	if (iter == ITER_MAX)
		return (0x00000000);
	else
		return (decide_colour(iter));
}*/