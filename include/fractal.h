/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:37:43 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 22:18:30 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

# include <X11/keysym.h>
# include <X11/X.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

// Define the screen resolution
# define WIDTH 800
# define HEIGHT 600

// Define some normal error
# define ERR_ALLOC "Something went wrong with memory allocation"
# define ERR_PARMS "You passed invalid values as parameter!"
# define EX_JULIA "./fractol julia -0.70176 -0.3842\n"
# define EX_MANDEL "./fractol mandelbrot\n"

enum e_set{
	MANDELBROT,
	JULIA
};

typedef struct s_image
{
	void	*mlx_image;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_fractal
{
	enum e_set	set;
	double		x;
	double		y;
	double		re;
	double		im;
	double		scale;
	t_image		*img;

}				t_fractal;

typedef struct s_data
{
	void		*display;
	void		*windows;
	t_fractal	*fractal;
}				t_data;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

int		encoder_argb(int r, int g, int b);
int		render_mandelbrot(t_image *img);
void	img_pix_put(t_image *img, int x, int y, int color);
int		start_mandel(t_data *data);
int		mouse_handler(int keysym, int x, int y, t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		handle_no_event(void *data);
int		mouse_handle(int keysym, int x, int y, t_data*data);
int		parser(char *str, char *re, char *im);
void	draw_fractal(t_data *client);
int		handle_keyrelease(int keysym, t_data *data);
int		expose_handler(t_data *data);
int		program_init(enum e_set set, double re, double im);
int		start_julia(t_data *data);
void	exit_program(t_data *data);
void	select_set(t_data *client);
#endif
