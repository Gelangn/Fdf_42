/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavas-g <anavas-g@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:27:38 by anavas-g          #+#    #+#             */
/*   Updated: 2024/05/21 21:02:28 by anavas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/mlx/mlx.h"
# include "../lib/mlx_linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf.h"
# include "../lib/libft/get_next_line.h"
// # include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <string.h>

# define WIN_W 1920
# define WIN_H 1080
# define MARGIN 50

# define PI 3.14159265359

# define MLX_ERROR 1
# define MLX_SUCCESS 0
# define MLX_EXIT 17
# define MLX_KEY_PRESS 2
# define MLX_KEY_RELEASE 3
# define MLX_NO_EVENT 0

# define DEFAULT_COLOR	MAGENTA
# define GROUND_COLOR	GREY

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define BLACK 0x000000
# define GREY 0x454545
# define BROWN 0x8B4513
# define ORANGE 0xFFA500
# define PINK 0xFFC0CB
# define PURPLE 0x800080
# define MY_COLOR 0x89CE94

# define ERR_ARGS	"\nIncorrect number of arguments, \
	expected 1, Usage: ./fdf <file.fdf>\n"
# define ERR_OPEN	"\nError opening the file\n"
# define ERR_READ	"\nError reading the file\n"
# define ERR_SPLIT	"\nError splitting the line\n"
# define ERR_LINE	"\nError: nº of elements is different for each line\n"
# define ERR_EMPTY	"\nError: the file is empty or wrongly formatted\n"
# define ERR_MEM	"\nCache error\n"
# define ERR_MAP	"\nMap Error\n"
# define ERR_MALLOC	"\nMalloc error\n"

/**** Estructuras ****/

// struct for bitmap

typedef struct s_img
{
	void	*img;		// image to be drawn on the window
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// struct for mlx

typedef struct s_var
{
	void	*mlx_conn;	// connection to the window
	void	*mlx_win;	// window to be drawn
}	t_var;

// struct for points

typedef struct s_point
{
	int		point_x;	// x coordinate of the point in the map
	int		point_y;	// y coordinate of the point in the map
	int		point_z;	// z coordinate of the point in the map
	int		color;		// color of the point in the map
	float	scrn_x;		// coordinate x in the screen
	float	scrn_y;		// coordinate y in the screen
}	t_point;

typedef struct s_dot
{
	float	xi;
	float	xf;
	float	yi;
	float	yf;
}	t_dot;

// struct for map

typedef struct s_map
{
	t_point	*points;	// array of points from map
	t_dot	*dot;		// array of dots from map
	char	**lines;	// array of lines from map
	int		fd;			// file descriptor
	char	*arg_path;	// path of the file
	int		width;		// width of the map
	int		height;		// height of the map
	int		nr_elems;	// number of elements in the map (width * height)
	float	scale;		// scale of the map
	int		origin_x;	// origin x of the map
	int		origin_y;	// origin y of the map
}	t_map;

// global struct to store all the structs

typedef struct s_global
{
	t_var		vars;
	t_img		img;
	t_map		map;
}	t_global;

/***** Prototipes *****/
/* MLX y eventos  */
int		handle_no_event(void);
int		handle_keypress(int keysym, t_global *global);
int		handle_keyrelease(int keysym);
int		handle_mouse_move(int x, int y);
int		mouse_press_hook(int button, int x, int y);
int		mouse_release_hook(int button, int x, int y);
void	set_hooks(t_global *global);

/* Window */
int		close_window(void *mlx);
void	*new_window(t_var *mlx);

/* Map */
t_map	read_map(t_map *map, char *arg_path);
void	free_map(t_map *map);

/* Graphics-Render-Draw */
void	render(t_global *global);
void	points_3d_to_2d(t_map *map);
void	isometric(t_point *point);
void	scale_map(t_map *map);
void	draw_line(t_img *img, t_dot *dot, int color);
void	pixel_put(t_img *data, int x, int y, int color);

/* Utils */
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		get_char_len(const char *chain, char chr);
void	finish(char *s);
void	free_global(t_global *global);
void	dbl_free(char **ptr);
void	check_map(t_map *map);
void	splited(t_map *map, int j, int i, int index);
int		ft_atoi_base(const char *str, int base);

#endif