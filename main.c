/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:21:40 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		error(char *err_message)
{
	ft_putendl_fd(err_message, 2);
	exit(EXIT_FAILURE);
}

void	set_map_defaults(t_map *map_data)
{
	map_data->zoom = WIN_WIDTH / (map_data->width) ;
	map_data->x_shift = WIN_WIDTH / 2;
	map_data->y_shift = WIN_HEIGHT / 2;
	map_data->z_scale = 3;
	map_data->projection = ISO;
}

int		main(int argc, char **argv)
{
	t_map	*map_data;

	if (argc != 2)
		error("Fdf needs exactly one argument");
	if (!(map_data = (t_map*)(malloc(sizeof(t_map)))))
		error("Memory allocation failed");
	read_file(argv[1], map_data);
	set_map_defaults(map_data);
	map_data->mlx_ptr = mlx_init();
	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT, "Stoopid window");
	map_data->img.img_ptr = mlx_new_image(map_data->mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT);
	map_data->img.addr = mlx_get_data_addr(map_data->img.img_ptr, \
		&map_data->img.bits_per_pixel, &map_data->img.line_length, \
		&map_data->img.endian);
	draw_map(map_data);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, \
		map_data->img.img_ptr, 0, 0);
	mlx_key_hook(map_data->win_ptr, key_hooks, map_data);
	mlx_loop(map_data->mlx_ptr);
	return (0);
}
