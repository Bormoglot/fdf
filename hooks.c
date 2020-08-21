/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:08:01 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h> 							// TO DELETE

static void	key_hook_zscale(int key, t_map *map_data)
{
	key == KEY_Z ? map_data->z_scale += 2 : 0;
	key == KEY_X ? map_data->z_scale -= 2 : 0;
}

static void	key_hook_shift(int key, t_map *map_data)
{
	key == KEY_UP_ARROW ? map_data->y_shift -= 10 : 0;
	key == KEY_DOWN_ARROW ? map_data->y_shift += 10 : 0;
	key == KEY_LEFT_ARROW ? map_data->x_shift -= 10 : 0;
	key == KEY_RIGHT_ARROW ? map_data->x_shift += 10 : 0;
}

static void	key_hook_change_projection(int key, t_map *map_data)
{
	key == KEY_P ? map_data->projection *= -1 : 0;
}

static void key_hook_zoom(int key, t_map *map_data)
{
	key == KEY_C ? map_data->zoom += 4 : 0;
	key == KEY_V ? map_data->zoom -= 4 : 0;
}

static void	key_hook_quit(int key, t_map *map_data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_image(map_data->mlx_ptr, map_data->img.img_ptr);
		mlx_destroy_window(map_data->mlx_ptr, map_data->win_ptr);
		free(map_data->colors);
		free(map_data->elevations);
		free(map_data);
		exit(EXIT_SUCCESS);
	}
}


int			key_hooks(int key, t_map *map_data)
{
	printf("%d\n", key);
	key_hook_quit(key, map_data);
	key_hook_shift(key, map_data);
	key_hook_zscale(key, map_data);
	key_hook_change_projection(key, map_data);
	key_hook_zoom(key, map_data);
	mlx_destroy_image(map_data->mlx_ptr, map_data->img.img_ptr);
	map_data->img.img_ptr = mlx_new_image(map_data->mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT);
	map_data->img.addr = mlx_get_data_addr(map_data->img.img_ptr, \
		&map_data->img.bits_per_pixel, \
		&map_data->img.line_length, &map_data->img.endian);
	draw_map(map_data);
	return (0);
}
