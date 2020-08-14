/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:46:36 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:43:28 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	isometric(int *x, int *y, int *z)
{
	*x = (*x - *y) * cos(0.52);
	*y = (*x + *y) * sin(0.52) - *z;
}

void	parallel(int *x, int *y, int *z)
{
	int k;
	int divisor;

	k = 20;
	divisor = *z + k;
	if (divisor == 0)
		divisor = 1; 
	*x = (k * *x) / divisor;
	*y = (k * *y) / divisor;
}

void	project(t_line *line, t_map *map_data)
{
	if (map_data->projection == ISO)
	{
		isometric(&(line->x0), &(line->y0), &(line->z0));
		isometric(&(line->x1), &(line->y1), &(line->z1));
	}
	if (map_data->projection == PARA)
	{
		parallel(&(line->x0), &(line->y0), &(line->z0));
		parallel(&(line->x1), &(line->y1), &(line->z1));
	}
}
