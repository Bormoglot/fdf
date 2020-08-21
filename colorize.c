/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:02:55 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/13 22:05:14 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static double	get_decimal(int min, int max, int curr)
{
	if ((curr == min) || (min == max))
		return (0.0);
	if (curr == max)
		return (1.0);
	return (((double)(curr - min)) / ((double)(max - min)));
}

int				set_default_color(int z, t_map *map_data)
{
	double	decimal;

	decimal = get_decimal(map_data->min_z, map_data->max_z, z);
	if (decimal < 0.1)
		return (COLOR_0_1);
	else if (decimal < 0.2)
		return (COLOR_1_2);
	else if (decimal < 0.3)
		return (COLOR_2_3);
	else if (decimal < 0.4)
		return (COLOR_3_4);
	else if (decimal < 0.5)
		return (COLOR_4_5);
	else if (decimal < 0.6)
		return (COLOR_5_6);
	else if (decimal < 0.7)
		return (COLOR_6_7);
	else if (decimal < 0.8)
		return (COLOR_7_8);
	else if (decimal < 0.9)
		return (COLOR_8_9);
	else
		return (COLOR_9_10);
}
