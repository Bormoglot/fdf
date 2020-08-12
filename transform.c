/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/12 22:48:22 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	zoom(t_line *line, t_map *map_data)
{
	line->x0 *= map_data->zoom;
	line->y0 *= map_data->zoom;
	line->x1 *= map_data->zoom;
	line->y1 *= map_data->zoom;
}

void	shift(t_line *line, t_map *map_data)
{
	line->x0 += map_data->x_shift;
	line->y0 += map_data->y_shift;
	line->x1 += map_data->x_shift;
	line->y1 += map_data->y_shift;
}

void	z_scale(t_line *line, t_map *map_data)
{
	line->z0 *= map_data->z_scale;
	line->z1 *= map_data->z_scale;
}
