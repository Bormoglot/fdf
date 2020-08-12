/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:45:24 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 20:27:15 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies no more than 'len' characters from string 'src' (including '\0')  to
** string 'dest'.  If 'src' < 'len'characters long, remainder of 'dest' is
** filles with '\0'. Otherwise, 'dest' is not terminated. Returns 'dest'.
*/

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*ptr;

	ptr = dest;
	while (*src != '\0' && len > 0)
	{
		*ptr = *src;
		++ptr;
		++src;
		--len;
	}
	while (len > 0)
	{
		*ptr = '\0';
		++ptr;
		--len;
	}
	return (dest);
}
