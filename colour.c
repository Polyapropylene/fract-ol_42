#include "fractol.h"

int	decide_colour(int iter, t_mlx *mlx)
{
	t_colour	colour;

	if (mlx->colour == 0)
	{
		colour.r = iter * 100 / mlx->max_iter + 200;
		colour.g = iter * 90 - 40;
		colour.b = (iter + 500) * 100 / mlx->max_iter;
	}
	if (mlx->colour == 1)
	{
		colour.r = 2 * iter;
		colour.g = 60 * iter / mlx->max_iter;
		colour.b = iter;
	}
	if (mlx->colour == 2)
	{
		colour.r = 350 * iter / mlx->max_iter + 10;
		colour.g = iter * mlx->max_iter / 150;
		colour.b = iter * iter;
	}
	return ((colour.r << 16) + (colour.g << 8) + colour.b);
}