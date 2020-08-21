/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/21 14:54:52 by jlavona          ###   ########.fr       */
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
	map_data->max_z = 0;
	map_data->min_z = 0;
	map_data->height = 0;
	map_data->width = 0;
	map_data->zoom = 0;
	map_data->x_shift = 0;
	map_data->y_shift = -130;
	map_data->z_scale = 3;
	map_data->projection = ISO;
}

void	set_mlx_ptrs(t_map *map_data)
{
	map_data->mlx_ptr = mlx_init();
	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT, "Stoopid window");
	map_data->img.img_ptr = mlx_new_image(map_data->mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT);
	map_data->img.addr = mlx_get_data_addr(map_data->img.img_ptr, \
		&map_data->img.bits_per_pixel, &map_data->img.line_length, \
		&map_data->img.endian);
}

int		main(int argc, char **argv)
{
	t_map	*map_data;
	int		fd;

	if (argc != 2)
		error("Fdf needs exactly one argument");
	if (!((fd = open(argv[1], O_RDONLY)) >= 0))
		error("Opening file failed");
	if (!(map_data = (t_map*)(malloc(sizeof(t_map)))))
		error("Memory allocation failed");
	set_map_defaults(map_data);
	read_file(fd, map_data);
	map_data->zoom = MIN(WIN_WIDTH / map_data->width, \
		WIN_HEIGHT / map_data->height);
	close(fd);
	set_mlx_ptrs(map_data);
	draw_map(map_data);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, \
		map_data->img.img_ptr, 0, 0);
	mlx_key_hook(map_data->win_ptr, key_hooks, map_data);
	mlx_loop(map_data->mlx_ptr);
	return (0);
}
