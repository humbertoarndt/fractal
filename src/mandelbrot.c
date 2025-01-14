/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:25:40 by johmatos          #+#    #+#             */
/*   Updated: 2022/10/24 22:25:44 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_color	get_color(int n)
{
	t_color	color;
	double	t;

	t = (double)n / (double)180;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}

static t_color	plot_mandel(t_fractal *fractal, int x, int y)
{
	int				n;
	double			temp;
	double			z;
	double			c;

	z = 0;
	c = 0;
	n = 0;
	fractal->re = ((float)x) / fractal->scale + fractal->x;
	fractal->im = ((float)y) / fractal->scale + fractal->y;
	while (n < 180 && z * z + c * c < 4.)
	{
		temp = (2 * z * c) + fractal->im;
		z = (z * z - c * c) + fractal->re;
		c = temp;
		n++;
	}
	return (get_color(n));
}

int	start_mandel(t_data *data)
{
	int				i;
	int				j;
	long int		row;
	t_color			color;
	t_fractal		*fractal;

	fractal = data->fractal;
	i = 0;
	while (i < fractal->img->height)
	{
		j = 0;
		while (j < fractal->img->width)
		{
			row = i * fractal->img->width;
			color = plot_mandel(fractal, j, i);
			((unsigned int *)fractal->img->addr)[j + row] = encoder_argb(
					color.r,
					color.g,
					color.b);
			j++;
		}
		i++;
	}
	draw_fractal(data);
	return (0);
}
