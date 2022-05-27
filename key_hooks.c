#include "fractol.h"

int	key_hooks(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
		close_window(mlx);
	if (keycode == W_KEY || keycode == UP_ARROW)
		mlx->y_center -= 50 / mlx->scale;
	if (keycode == S_KEY || keycode == DOWN_ARROW)
		mlx->y_center += 50 / mlx->scale;
	if (keycode == A_KEY || keycode == LEFT_ARROW)
		mlx->x_center -= 50 / mlx->scale;
	if (keycode == D_KEY || keycode == RIGHT_ARROW)
		mlx->x_center += 50 / mlx->scale;
	if (keycode == 24)
		mlx->scale *= 2;
	if (keycode == 27)
		mlx->scale /= 2;
	if (keycode == 18)
		mlx->colour = 1;
	if (keycode == 19)
		mlx->colour = 2;
	if (keycode == 29)
		mlx->colour = 0;
	redraw(mlx);
	return(0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	mlx->x_center = ((x - (WIN_W / 2)) / mlx->scale + mlx->x_center);
	mlx->y_center = ((y - (WIN_H / 2)) / mlx->scale + mlx->y_center);
	if (button == SCROLL_UP)
		mlx->scale *= 2;
	else if (button == SCROLL_DOWN)
		mlx->scale /= 2;
	redraw(mlx);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}