/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:03:17 by anavas-g          #+#    #+#             */
/*   Updated: 2024/04/14 22:31:03 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// To draw the map we need to draw the horizontal lines
static void	right_line(t_global *global, int index)
{
	t_dot	*dot;

	dot = malloc(sizeof(t_dot));
	dot->xi = (global->map.points[index].scrn_x * global->map.scale)
		+ global->map.origin_x;
	dot->yi = (global->map.points[index].scrn_y * global->map.scale)
		+ global->map.origin_y;
	dot->xf = (global->map.points[index + 1].scrn_x * global->map.scale)
		+ global->map.origin_x;
	dot->yf = (global->map.points[index + 1].scrn_y * global->map.scale)
		+ global->map.origin_y;
	draw_line(&global->img, dot, global->map.points[index].color);
	free(dot);
}

// To draw the map we need to draw the vertical lines
static void	down_line(t_global *global, int index)
{
	t_dot	*dot;

	dot = malloc(sizeof(t_dot));
	dot->xi = (global->map.points[index].scrn_x * global->map.scale)
		+ global->map.origin_x;
	dot->yi = (global->map.points[index].scrn_y * global->map.scale)
		+ global->map.origin_y;
	dot->xf = (global->map.points[index + global->map.width].scrn_x
			* global->map.scale) + global->map.origin_x;
	dot->yf = (global->map.points[index + global->map.width].scrn_y
			* global->map.scale) + global->map.origin_y;
	draw_line(&global->img, dot, global->map.points[index].color);
	free(dot);
}

// for each point in the map we draw the horizontal and vertical lines
static void	draw_map(t_global *global)
{
	int	index;

	index = 0;
	while (index < global->map.nr_elems)
	{
		if (index % global->map.width != global->map.width - 1)
			right_line(global, index);
		if (index < global->map.nr_elems - global->map.width)
			down_line(global, index);
		index++;
	}
	free(global->map.points);
}

void	render(t_global *global)
{
	points_3d_to_2d(&global->map);
	scale_map(&global->map);
	draw_map(global);
}
