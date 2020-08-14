/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:00:12 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/13 22:05:26 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
