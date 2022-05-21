#include "fractol.h"

void	init(t_mlx *mlx)
{
	mlx->scale = 200;
	mlx->x_center = 0;
	mlx->y_center = 0;
}

void	draw(t_mlx *mlx)
{
	int	x;
	int	y;
	t_cmplx	z;
	y = -1;
	z.x = 0;
	z.y = 0;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			z.y = ((y - (WIN_H / 2)) / mlx->scale + mlx->y_center);
			z.x = ((x - (WIN_W / 2)) / mlx->scale + mlx->x_center);
			mlx->img.data[y * WIN_W + x] = choose_fractal(mlx, &z);
		}
	}
}

void	redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
			&(mlx->img.size_l), &(mlx->img.endian));
	draw(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	if (argc > 1)
	{
		check_args(&mlx, argv[1]);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIN_W, WIN_H, "fractol");
		mlx.img.img_ptr = mlx_new_image(mlx.mlx, WIN_W, WIN_H);
		mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
		init(&mlx);
		draw(&mlx);
		mlx_key_hook(mlx.win, key_hooks, &mlx);
		mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putstr("Wrong number of arguments!\n");
}
