/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw _utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:03:17 by anavas-g          #+#    #+#             */
/*   Updated: 2024/04/15 18:14:52 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + ((y * data->line_length) + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// To calculate the lines we use the DDA algorithm, not Bresenham
void	draw_line(t_img *img, t_dot *dot, int color)
{
	float	step;
	double	deltax;
	double	deltay;
	int		i;

	i = 0;
	step = 0.0;
	deltax = dot->xf - dot->xi;
	deltay = dot->yf - dot->yi;
	step = sqrt((deltax * deltax) + (deltay * deltay));
	deltax = deltax / step;
	deltay = deltay / step;
	if (step == 0)
		pixel_put(img, (int)dot->xi, (int)dot->yi, color);
	while (i < step)
	{
		pixel_put(img, (int)dot->xi, (int)dot->yi, color);
		dot->xi += deltax;
		dot->yi += deltay;
		i++;
	}
}
