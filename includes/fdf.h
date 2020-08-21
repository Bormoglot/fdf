/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:05:11 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:11:20 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
# define WIN_HEIGHT 800
# define WIN_WIDTH 1000
# define ISO 1
# define PARA -1

//# ifdef __linux__
#  define KEY_UP_ARROW 65362
#  define KEY_DOWN_ARROW 65364
#  define KEY_LEFT_ARROW 65361
#  define KEY_RIGHT_ARROW 65363
#  define KEY_ESCAPE 65307
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_P 112
#  define KEY_C 99
#  define KEY_V 118
//# endif

/*
#  define KEY_UP_ARROW 126
#  define KEY_DOWN_ARROW 125
#  define KEY_LEFT_ARROW 123
#  define KEY_RIGHT_ARROW 124
#  define KEY_ESCAPE 53
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_P 35
*/

/*
# define TEXT_COLOR		0x14FCF2
# define BACKGROUND		0x000000
*/

# define COLOR_0_1		0x34E500
# define COLOR_1_2		0x76E100
# define COLOR_2_3		0xB7DD00
# define COLOR_3_4		0xD98D00
# define COLOR_4_5		0xD57A00
# define COLOR_5_6		0xD23800
# define COLOR_6_7		0xCE0005
# define COLOR_7_8		0xCA0042
# define COLOR_8_9		0xC6007D
# define COLOR_9_10		0xC200B5

/*
** Type for putting pixels
*/

typedef struct		s_img {
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

/*
** Type for map
**
** width		width of map in symbols
** height		height of map in symbols
** zoom			zoom
**
** elevations	array of elevation values
** colors		array of hex color values
** max_z		maximum elevation
** min_z		minimum elevation
*/

typedef struct	s_map {
	int				width;
	int				height;
	int				zoom;
	int				x_shift;
	int				y_shift;
	int				z_scale;
	int				projection;
	int				*elevations;
	int				*colors;
	int				max_z;
	int				min_z;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
}					t_map;

/*
** Type for intermediate list (elevation and color)
*/

typedef struct		s_zlist {
	int				z;
	int				color;
	struct	s_zlist	*next;
}					t_zlist;

/*
** Type for point
*/


typedef struct s_point {

	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

/*
** Type for Bresenham's line algorithm variables
*/

typedef struct	s_bresvars {
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		err;
	int		err2;
}				t_bresvars;

/*
** List and validation functions
*/

int		valid_color(const char *str);
int		validate_values(const char *str, int offset);
t_zlist	*new_node(char *str);
void	add_node(t_zlist **lst, t_zlist *new);
t_zlist	*get_last_node(t_zlist **lst);

int		set_default_color(int z, t_map *map_data);

void	read_file(const int fd, t_map *map_data);
void	draw_line(t_point p0, t_point p1, t_map *map_data);
void	draw_map(t_map *map_data);

int		key_hooks(int key, t_map *map_data);
int		error(char *err_message);

#endif
