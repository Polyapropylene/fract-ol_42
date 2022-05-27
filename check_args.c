#include "fractol.h"

void	check_args(t_mlx *mlx, char **argv, int argc)
{
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		mlx->type = 1;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		mlx->type = 2;
		mlx->julia.jr = atof(argv[2]);
		mlx->julia.ji = atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "Newton", 6) == 0)
		mlx->type = 3;
	else
	{
		ft_putstr("Wrong arguments!\n");
		exit(0);
	}
}

int	choose_fractal(t_mlx *mlx, t_cmplx *z)
{
	if (mlx->type == 1)
		return (iter_mandelbrot(z, mlx));
 	else if (mlx->type == 2)
	{
		z->ji = mlx->julia.ji;
		z->jr = mlx->julia.jr;
		return (iter_julia(z, mlx));
	}
	else if (mlx->type == 3)
		return (iter_newton(z, mlx));
	return (0);
}