/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2019/10/28 11:00:06 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
** TODO
** - do errorcheck on file operations and gnl
*/

int		get_width(const char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int		get_height(const char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

/*
** Fills one line of coordinate matrix.
**
*/

void	fill_coords_line(int *coords_line, char *line)
{
	char	**numbers;
	int		i;

	numbers = ft_strsplit(line, ' ');
	i = 0;
	while (numbers[i])
	{
		coords_line[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void	read_file(char *file_name, t_map *map_data)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	map_data->width = get_width(file_name);
	map_data->height = get_height(file_name);

	map_data->coords = (int **)malloc(sizeof(int*) * (map_data->height + 1));
	i = 0;
	while (i <= map_data->height)
		map_data->coords[i++] = (int *)malloc(sizeof(int) * (map_data->width + 1));
	fd = open(file_name, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line))
	{
		fill_coords_line(map_data->coords[j], line);
		free(line);
		++j;
	}
	close(fd);
	map_data->coords[j] = NULL;
}
