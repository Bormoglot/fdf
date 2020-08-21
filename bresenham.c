/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:00:12 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/21 14:55:58 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h>

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

void	draw_line(t_point p0, t_point p1, t_map *map_data)
{
	t_bresvars	b;

	b.delta_x = abs(p1.x - p0.x);
	b.delta_y = -abs(p1.y - p0.y);
	b.sign_x = p0.x < p1.x ? 1 : -1;
	b.sign_y = p0.y < p1.y ? 1 : -1;
	b.err = b.delta_x + b.delta_y;
	while (1)
	{
		my_mlx_pixel_put(map_data, p0.x, p0.y, p0.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		b.err2 = 2 * b.err;
		if (b.err2 >= b.delta_y)
		{
			b.err += b.delta_y;
			p0.x += b.sign_x;
		}
		if (b.err2 <= b.delta_x)
		{
			b.err += b.delta_x;
			p0.y += b.sign_y;
		}
	}
}
