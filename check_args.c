#include "fractol.h"

void	check_args(t_mlx *mlx, char *argv)
{
	if (ft_strncmp(argv, "Mandelbrot", 11) == 0)
		mlx->type = 1;
	else if (ft_strncmp(argv, "Julia", 5) == 0)
	{
		mlx->type = 2;
	}
	else
	{
		ft_putstr("Wrong arguments!\n");
		exit(0);
	}
}

int	choose_fractal(t_mlx *mlx, t_cmplx *z)
{
	if (mlx->type == 1)
		return (iter_mandelbrot(z));
	// else if (mlx->type == 2)
	// 	return (iter_julia(z));
	return (0);
}