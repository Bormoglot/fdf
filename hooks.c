/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2019/10/28 11:00:06 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h>

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

static void	key_hook_quit(int key, t_map *map_data)
{
	int 	i;

	if (key == KEY_ESCAPE)
	{
		i = 0;

		while (i <= map_data->height)
		{
			free(map_data->coords[i++]);
		}
		/*
		** Free not working? Loses 80 bytes on 42.fdf
		*/
		free(map_data->coords);
		mlx_destroy_image(map_data->mlx_ptr, map_data->img.img_ptr);
		mlx_destroy_window(map_data->mlx_ptr, map_data->win_ptr);
		free(map_data);
		exit(EXIT_SUCCESS);
	}
}

int		key_hooks(int key, t_map *map_data)
{
	printf("%d\n", key);
	key_hook_quit(key, map_data);
	key_hook_shift(key, map_data);
	key_hook_zscale(key, map_data);
	mlx_destroy_image(map_data->mlx_ptr, map_data->img.img_ptr);
	map_data->img.img_ptr = mlx_new_image(map_data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	map_data->img.addr = mlx_get_data_addr(map_data->img.img_ptr, &map_data->img.bits_per_pixel, \
		&map_data->img.line_length, &map_data->img.endian);
	draw_map(map_data);

	return (0);
}
