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

int		chars_ok(char *ch)
{
	int	res;
	int i;

	i = 0;
	res = 1;
	while (ch[i])
	{
		if (!ft_isdigit(ch[i]) && ch[i] != ' ' && ch[i] != '-' && ch[i] != '+')
			res = 0;
		++i;
	}
	return (res);
}

void	set_height_width(const char *file_name, t_map *map_data)
{
	int			fd;
	char		*line;

	fd = open(file_name, O_RDONLY);
	map_data->width = 0;
	map_data->height = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!chars_ok(line))
		{
			free(line);
			error("Invalid character in map file");
		}
		if (map_data->width == 0)
			map_data->width = (int)ft_wordcount(line, ' ');
		else if (map_data->width != (int)ft_wordcount(line, ' '))
		{
			free(line);
			error("Invalid map: unequal rows");
		}
		free(line);
		++(map_data->height);
	}
	close(fd);
}

/*
** Fills one line of coordinate matrix
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

	set_height_width(file_name, map_data);
	if (!(map_data->coords = (int **)malloc(sizeof(int*) * \
	(map_data->height + 1))))
		error("Memory allocation failed");
	i = 0;
	while (i < (map_data->height))
	{
		if (!(map_data->coords[i++] = (int *)malloc(sizeof(int) * \
		(map_data->width + 1))))
			error("Memory allocation failed");
	}
	fd = open(file_name, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line))
	{
		fill_coords_line(map_data->coords[j++], line);
		free(line);
	}
	close(fd);
	map_data->coords[j] = NULL;
}
