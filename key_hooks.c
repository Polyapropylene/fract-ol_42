#include "fractol.h"

int	key_hooks(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == W_KEY || keycode == UP_ARROW)
		mlx->y_center -= 50 / mlx->scale;
	if (keycode == S_KEY || keycode == DOWN_ARROW)
		mlx->y_center += 50 / mlx->scale;
	if (keycode == A_KEY || keycode == LEFT_ARROW)
		mlx->x_center -= 50 / mlx->scale;
	if (keycode == D_KEY || keycode == RIGHT_ARROW)
		mlx->x_center += 50 / mlx->scale;
	if (keycode == 24)
		mlx->scale += 75;
	if (keycode == 27)
		mlx->scale -= 75;
	redraw(mlx);
	return(0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == SCROLL_UP)
	{
		mlx->x_center = (x / mlx->scale + mlx->x_center) - (x / (mlx->scale + 75));
		mlx->y_center = (y / mlx->scale + mlx->y_center) - (y / (mlx->scale + 75));
		mlx->scale += 75;
	}
	else if (button == SCROLL_DOWN)
	{
		mlx->x_center = (x / mlx->scale + mlx->x_center) - (x / (mlx->scale - 75));
		mlx->y_center = (y / mlx->scale + mlx->y_center) - (y / (mlx->scale - 75));
		mlx->scale -= 75;
	}
	redraw(mlx);
	return (0);
}