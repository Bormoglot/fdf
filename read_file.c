/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:00:31 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"
#include <stdio.h>							// TO DE:ETE

/*
** Allocates and fills elevations and colors arrays.
** Finds minimum and maximum elevation.
*/

void			fill_z_and_color(t_zlist **lst, t_map *map_data)
{
	t_zlist		*node;
	int			size;

	size = map_data->width * map_data->height;
	printf("size is %d\n", size);
	if ((!(map_data->elevations = (int *)ft_memalloc(sizeof(int) * size)))
		|| (!(map_data->colors = (int *)ft_memalloc(sizeof(int) * size))))
		error("Memory allocation failed");
	while ((node = get_last_node(lst)))
	{
		map_data->elevations[size - 1] = node->z;
		map_data->colors[size - 1] = node->color;
		if (node->z > map_data->max_z)
			map_data->max_z = node->z;
		if (node->z < map_data->min_z)
			map_data->min_z = node->z;
		size--;
		free(node);
	}
}

void	read_file(const int fd, t_map *map_data)
{
	int		i;
	char	*line;
	char	**numbers;
	t_zlist	*list;

	list = NULL;
	while ((get_next_line(fd, &line)))
	{
		if (!(numbers = ft_strsplit(line, ' ')))
			error("Reading map failed");
		i = -1;
		while (numbers[++i])
		{
			add_node(&list, new_node(numbers[i]));
			free(numbers[i]);
		}
		free(numbers);
		if (map_data->height == 0)
			map_data->width = i;
		if (map_data->width != (int)ft_wordcount(line, ' '))
			error("Invalid map: unequal rows");
		free(line);
		map_data->height++;
	}
	fill_z_and_color(&list, map_data);
	map_data->zoom = MIN(WIN_WIDTH / map_data->width, WIN_HEIGHT / map_data->height);
}
