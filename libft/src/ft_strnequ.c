/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:54:57 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 21:42:08 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if up to 'n' characters in strings 's1' and 's2' are equal,
** 0 - otherwise
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return (s1 && s2 && !(ft_strncmp(s1, s2, n)));
}
