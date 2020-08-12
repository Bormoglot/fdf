/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 22:02:22 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/25 11:28:29 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compares no more than 'count' characters of strings 's1'
** and 's2'. Returns 0 if characters are equal, int > 0 if 's1' > 's2',
** int < 0 if 's1' < 's2'
*/

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	if (count == 0)
		return (0);
	while ((*s1 == *s2) && (count > 1))
	{
		if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
		--count;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
