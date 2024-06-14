/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:03:17 by anavas-g          #+#    #+#             */
/*   Updated: 2024/05/22 00:20:56 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(t_point *point)
{
	double	angle;

	angle = PI / 6;
	point->scrn_x = (point->point_x - point->point_y) * cos(angle);
	point->scrn_y = (point->point_x + point->point_y) * sin(angle) \
		- point->point_z;
}

void	points_3d_to_2d(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nr_elems)
	{
		isometric(&map->points[i]);
		i++;
	}
}
