/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:31:43 by anavas-g          #+#    #+#             */
/*   Updated: 2024/04/15 18:06:01 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->lines[i])
	{
		free(map->lines[i]);
		i++;
	}
	free(map->lines);
}

void	free_global(t_global *global)
{
	free_map(&global->map);
	free(global->img.img);
	free(global->vars.mlx_win);
	free(global->vars.mlx_conn);
}

void	dbl_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}
