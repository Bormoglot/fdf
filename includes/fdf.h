/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:05:11 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/12 22:01:18 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define WIN_HEIGHT 400
# define WIN_WIDTH 700
# define ISO 1
# define PARA 2

/*/# ifdef __linux__
#  define KEY_UP_ARROW 65362
#  define KEY_DOWN_ARROW 65364
#  define KEY_LEFT_ARROW 65361
#  define KEY_RIGHT_ARROW 65363
#  define KEY_ESCAPE 65307
#  define KEY_Z 122
#  define KEY_X 120
//# endif
*/

#  define KEY_UP_ARROW 126
#  define KEY_DOWN_ARROW 125
#  define KEY_LEFT_ARROW 123
#  define KEY_RIGHT_ARROW 124
#  define KEY_ESCAPE 53
#  define KEY_Z 6
#  define KEY_X 7

/*
** Type for putting pixels
*/

typedef struct  s_img {
    void        *img_ptr;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

/*
** Type for map
**
** width	width of map in symbols
** height	height of map in symbols
** zoom		zoom
**
*/

typedef struct	s_map {
	int			width;
	int			height;
	int			zoom;
	int			color;
	int			x_shift;
	int			y_shift;
	int			z_scale;
	int			projection;
	int			**coords;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_map;

/*
** Type for line
*/

typedef struct	s_line {

	int			x0;
	int			y0;
	int			z0;
	int			x1;
	int			y1;
	int			z1;
}				t_line;

/* 
** Type for Bresenham's line algorithm variables
*/

typedef struct	s_bresvars {
    int     dx;
    int     dy;
    int     sx;
    int     sy;
    int     err;
    int     err2;
}				t_bresvars;



void	read_file(char *file_name, t_map *map_data);
void	draw_line(t_line *line, t_map *map_data);
void	draw_map(t_map *map_data);
void 	project(t_line	*line, t_map *map_data);
void	zoom(t_line *line, t_map *map_data);
void	shift(t_line *line, t_map *map_data);
void	z_scale(t_line	*line, t_map *map_data);
int		key_hooks(int key, t_map *map_data);

#endif
