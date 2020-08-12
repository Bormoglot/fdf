/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/12 22:58:30 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h>						// TO DELETE

void	my_mlx_pixel_put(t_map *map_data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = map_data->img.addr + (y * map_data->img.line_length + \
		x * (map_data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
** Bresenham's line algorithm
*/

void	use_bresenham(t_line *line, t_map *map_data)
{
	t_bresvars	b;

	b.dx = abs(line->x1 - line->x0);
	b.dy = -abs(line->y1 - line->y0);
	b.sx = line->x0 < line->x1 ? 1 : -1;
	b.sy = line->y0 < line->y1 ? 1 : -1;
	b.err = b.dx + b.dy;
	while (1)
	{
		my_mlx_pixel_put(map_data, line->x0, line->y0, map_data->color);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		b.err2 = 2 * b.err;
		if (b.err2 >= b.dy)
		{
			b.err += b.dy;
			line->x0 += b.sx;
		}
		if (b.err2 <= b.dx)
		{
			b.err += b.dx;
			line->y0 += b.sy;
		}
	}
}

void	colorize(t_line *line, t_map *map_data)
{
	map_data->color = (line->z0 || line->z1) ? 0x00FF0000 : 0x00FFFFFF;
}

/*
** Main drawing function
*/

void	draw_line(t_line *line, t_map *map_data)
{
	zoom(line, map_data);
	z_scale(line, map_data);
	colorize(line, map_data);
	project(line, map_data);
	shift(line, map_data);
	use_bresenham(line, map_data);
}

t_line	*init_line(void)
{
	t_line	*line;

	line = (t_line*)(malloc(sizeof(t_line)));
	line->x0 = 0;
	line->y0 = 0;
	line->x1 = 0;
	line->y1 = 0;
	line->z0 = 0;
	line->z1 = 0;
	return (line);
}

void	draw_map(t_map *map_data)
{
	t_line		*line;
	int			x;
	int			y;

	line = init_line();
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (x < map_data->width - 1)
			{
				line->x0 = x;
				line->y0 = y;
				line->z0 = map_data->coords[y][x];
				line->x1 = x + 1;
				line->y1 = y;
				line->z1 = map_data->coords[line->y1][line->x1];
				draw_line(line, map_data);
			}
			if (y < map_data->height - 1)
			{
				line->x0 = x;
				line->y0 = y;
				line->z0 = map_data->coords[y][x];
				line->x1 = x;
				line->y1 = y + 1;
				line->z1 = map_data->coords[line->y1][line->x1];
				draw_line(line, map_data);
			}
			++x;
		}
		++y;
	}
	free(line);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, \
		map_data->img.img_ptr, 0, 0);
}
