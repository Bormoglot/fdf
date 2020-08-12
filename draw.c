/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2019/10/28 11:00:06 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h>						// TO DELETE

void		my_mlx_pixel_put(t_map *map_data, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WIN_WIDTH || y <= 0 || y >= WIN_HEIGHT)
		return ;
	dst = map_data->img.addr + (y * map_data->img.line_length + x * (map_data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.52);
	*y = (*x + *y) * sin(0.52) - z;
}

void		parallel(int *x, int *y, int z)
{
	int k;

	k = 30;
	*x = (k * *x)/(z + k);
	*y = (k * *y)/(z + k);
}

/* Bresenham's line algorithm */

void            draw_line(t_line *line, t_map *map_data)
{
    t_bresvars	b;

	line->z0 = map_data->coords[line->y0][line->x0];
	line->z1 = map_data->coords[line->y1][line->x1];

	zoom(line, map_data);
	z_scale(line, map_data);

	map_data->color = (line->z0 || line->z1) ? 0x00FF0000 : 0xFFFFFFFF;

	isometric(&(line->x0), &(line->y0), line->z0);
	isometric(&(line->x1), &(line->y1), line->z1);
	//parallel(&(line->x0), &(line->y0), line->z0);
	//parallel(&(line->x1), &(line->y1), line->z1);

	shift(line, map_data);

    b.dx = abs(line->x1 - line->x0);
    b.dy = -abs(line->y1 - line->y0);
    b.sx = line->x0 < line->x1 ? 1 : -1;
    b.sy = line->y0 < line->y1 ? 1 : -1;
    b.err = b.dx + b.dy;
    while (1)
    {
        my_mlx_pixel_put(map_data, line->x0, line->y0, map_data->color);
        if (line->x0 == line->x1 && line->y0 == line->y1)
            break;
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
	int 		x;
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
				line->x1 = x + 1;
				line->y1 = y;
				draw_line(line, map_data);
			}
			if (y < map_data->height - 1)
			{
				line->x0 = x;
				line->y0 = y;
				line->x1 = x;
				line->y1 = y + 1;
				draw_line(line, map_data);
			}
			++x;
		}
		++y;
	}
	free(line);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, map_data->img.img_ptr, 0, 0);
}
