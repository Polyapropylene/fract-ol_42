#include "fractol.h"

int	iter_mandelbrot(t_cmplx *z, t_mlx *mlx)
{
	int		iter;
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
		return (decide_colour(iter, mlx));
}

int	iter_julia(t_cmplx *z, t_mlx *mlx)
{
	int		iter;
	double	tmp;
	
	iter = 0;
	while (iter < ITER_MAX && (z->x * z->x + z->y * z->y) <= 4)
	{
		tmp = z->x;
		z->x = z->x * z->x - z->y * z->y + z->jr;
		z->y = 2 * tmp * z->y + z->ji;
		iter++;
	}
	if (iter == ITER_MAX)
		return (0x00000000);
	else
		return (decide_colour(iter, mlx));
}

int	iter_newton(t_cmplx *z, t_mlx *mlx)
{
	int	iter;
	double	tmp;
	
	iter = 0;
	z->x0 = z->x;
	z->y0 = z->y;
	while (iter < ITER_MAX && (z->x * z->x + z->y * z->y) <= 16)
	{
		tmp = z->x;
		//z->x -= (pow(z->x, 5) + 2 * pow(z->x, 3) * pow(z->y, 2) - pow(z->x, 2) + z->x * pow(z->y, 4) + pow(z->y, 2)) / (3 * pow((pow(z->x, 2) + pow(z->y, 2)), 2));
		//z->y -= (z->y * (pow(tmp, 4) + pow(z->y, 4) + 2 * tmp + 2 * pow(tmp, 2) * pow(z->y, 2))) / (3 * pow((pow(tmp, 2) + pow(z->y, 2)), 2));
		z->x -= (z->x * z->x * z->x * z->x * z->x + 2 * z->x * z->x * z->x * z->y * z->y - z->x * z->x + z->x * z->y * z->y * z->y * z->y + z->y * z->y) / (3 * (z->x * z->x + z->y * z->y) * (z->x * z->x + z->y * z->y));
		z->y -= (z->y * (tmp * tmp * tmp * tmp + z->y * z->y * z->y * z->y + 2 * tmp + 2 * tmp * tmp * z->y * z->y)) / (3 * (tmp * tmp + z->y*z->y)*(tmp * tmp + z->y * z->y));
		iter++;
	}
	if (iter == ITER_MAX)
		return (0x00000000);
	else
		return (decide_colour(iter, mlx));
}