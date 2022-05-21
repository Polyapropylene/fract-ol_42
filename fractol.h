#ifndef FRACTOL_H
# define FRACTOL_H

# include "../fract-ol_42/minilibx/mlx.h"
# include "../fract-ol_42/libft/libft.h"
# include <stdlib.h>

# define WIN_W 1000
# define WIN_H 1000

# define ITER_MAX 100

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define LEFT_ARROW 123
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define UP_ARROW 126

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
} t_img;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
	int	shift;
} t_colour;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	long double	y_center;
	long double	x_center;
	long double	scale;
	int			type;
} t_mlx;

typedef struct s_cmplx
{
	double	x;
	double	y;
	double	x0;
	double	y0;
} t_cmplx;

int		key_hooks(int keycode, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, t_mlx *mlx);
int		iter_mandelbrot(t_cmplx *z);
int		iter_julia(t_cmplx *z);
int		decide_colour(int iter);
void	draw(t_mlx *mlx);
void		redraw(t_mlx *mlx);
void	check_args(t_mlx *mlx, char *argv);
int		choose_fractal(t_mlx *mlx, t_cmplx *z);

#endif
