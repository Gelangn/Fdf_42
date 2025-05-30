/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:27:02 by anavas-g          #+#    #+#             */
/*   Updated: 2024/04/14 22:47:45 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_hooks(t_global *global)
{
	mlx_do_key_autorepeatoff(global->vars.mlx_conn);
	mlx_loop_hook(global->vars.mlx_conn, &handle_no_event, &global->vars);
	mlx_hook(global->vars.mlx_win, 2, 1L << 0, &handle_keypress, NULL);
	mlx_hook(global->vars.mlx_win, 17, 1L << 0, &handle_keypress, NULL);
	mlx_hook(global->vars.mlx_win, 3, 1L << 0, &handle_keyrelease, NULL);
	mlx_hook(global->vars.mlx_win, 1, 1L << 6, &mouse_press_hook, NULL);
	mlx_hook(global->vars.mlx_win, 5, 1L << 6, &mouse_release_hook, NULL);
	mlx_hook(global->vars.mlx_win, 6, 1L << 6, &handle_mouse_move, NULL);
}

/* This function needs to exist, but is useless by the moment */
int	handle_no_event(void)
{
	return (0);
}

int	mouse_press_hook(int button, int x, int y)
{
	ft_printf("Mouse button %d pressed at position (%d, %d)\n", button, x, y);
	return (0);
}

int	mouse_release_hook(int button, int x, int y)
{
	ft_printf("Mouse button %d released at position (%d, %d)\n", button, x, y);
	return (0);
}
