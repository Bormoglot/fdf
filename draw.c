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
#include <stdio.h> 				// TO DE:ETE

t_point			new_point(int x, int y, t_map *map_data)
{
	t_point		point;
	int			ix;

	ix = y * map_data->width + x;
	point.x = x;
	point.y = y;
	point.z = map_data->elevations[ix];
	point.color = (map_data->colors[ix] == -1) ?
		set_default_color(point.z, map_data) : map_data->colors[ix];
	return (point);
}

void	isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.52);
	*y = (*x + *y) * sin(0.52) - z;
}

t_point			transform(int x, int y, t_map *map_data)
{
	t_point	point;

	point = new_point(x, y, map_data);
	point.x *= map_data->zoom;
	point.y *= map_data->zoom;
	point.z *= map_data->z_scale;
	point.x -= (map_data->width * map_data->zoom) / 2;
	point.y -= (map_data->height * map_data->zoom) / 2;
	//ft_rotate_xyz(&p.x, &p.y, &p.z, fdf);
	if (map_data->projection == ISO)
		isometric(&point.x, &point.y, point.z);
	point.x += WIN_WIDTH / 2 + map_data->x_shift;
	point.y += (WIN_HEIGHT + map_data->height * map_data->zoom) / 2
		+ map_data->y_shift;
	return (point);
}

/*
** Main drawing function
*/

void	get_coords_draw(t_map *map_data)
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
				draw_line(transform(x, y, map_data), transform(x + 1, y, \
				map_data), map_data);
			if (y < map_data->height - 1)
				draw_line(transform(x, y, map_data), transform(x, y + 1, \
				map_data), map_data);
			++x;
		}
		++y;
	}
}

void	draw_map(t_map *map_data)
{
	ft_bzero(map_data->img.addr, WIN_WIDTH * WIN_HEIGHT * (map_data->img.bits_per_pixel / 8));
	get_coords_draw(map_data);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, \
		map_data->img.img_ptr, 0, 0);
}
