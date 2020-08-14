/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 04:04:01 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
** Main drawing function
*/

void	draw_line(t_line *line, t_map *map_data)
{
	line->z0 = map_data->coords[line->y0][line->x0];
	line->z1 = map_data->coords[line->y1][line->x1];
	zoom(line, map_data);
	z_scale(line, map_data);
	colorize(line, map_data);
	project(line, map_data);
	shift(line, map_data);
	use_bresenham(line, map_data);
}

void	fill_first_point(t_line *line, int x, int y)
{
	line->x0 = x;
	line->y0 = y;
}

void	fill_second_point(t_line *line, int x, int y)
{
	line->x1 = x;
	line->y1 = y;
}

void	get_coords_draw(t_line *line, t_map *map_data)
{
	int		x;
	int		y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (x < map_data->width - 1)
			{
				fill_first_point(line, x, y);
				fill_second_point(line, x + 1, y);
				draw_line(line, map_data);
			}
			if (y < map_data->height - 1)
			{
				fill_first_point(line, x, y);
				fill_second_point(line, x, y + 1);
				draw_line(line, map_data);
			}
			++x;
		}
		++y;
	}
}

void	draw_map(t_map *map_data)
{
	t_line		*line;

	line = (t_line*)(malloc(sizeof(t_line)));
	ft_bzero(line, sizeof(t_line));
	get_coords_draw(line, map_data);
	free(line);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, \
		map_data->img.img_ptr, 0, 0);
}
