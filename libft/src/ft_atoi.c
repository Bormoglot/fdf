/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:20:30 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/15 19:00:48 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		++s;
	}
	while (*s != '\0' && ft_isdigit(*s))
	{
		result *= 10;
		result += (*s - '0');
		++s;
	}
	return (result * sign);
}
