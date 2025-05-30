/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:31:06 by anavas-g          #+#    #+#             */
/*   Updated: 2024/04/15 18:05:54 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(void *mlx)
{
	t_global	*global;

	ft_printf("Closing window\n");
	mlx = NULL;
	if (mlx != NULL)
	{
		global = (t_global *)mlx;
		if (global->vars.mlx_conn != NULL && global->vars.mlx_win != NULL)
		{
			ft_printf("Destroying window\n");
			mlx_destroy_window(global->vars.mlx_conn, global->vars.mlx_win);
		}
	}
	return (MLX_SUCCESS);
}

void	*new_window(t_var *mlx)
{
	ft_printf("Creating window\n");
	mlx->mlx_win = mlx_new_window(mlx->mlx_conn, WIN_W, WIN_H, \
			"Welcome to FdF - anavas-g");
	if (!mlx->mlx_win)
	{
		free(mlx->mlx_win);
		return (NULL);
	}
	ft_printf("Window created\n");
	mlx_string_put(mlx->mlx_conn, mlx->mlx_win, \
		WIN_W * .89, WIN_H * .96, 0x00FF0000, "By anavas-g");
	return (mlx->mlx_win);
}
