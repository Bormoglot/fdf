/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:57:16 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/25 18:15:57 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends NUL-terminated string 'src' at the end of string 'dest'. Will append
** at most 'destsize' - ft_strlen(dest) - 1 bytes, NUL-terminating the result.
** 'destsize' - length of result, including '\0'.
** Returns total length of the string that it tried to create.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < destsize)
		++i;
	while (src[j] != '\0' && (i + j + 1) < destsize)
	{
		dest[i + j] = src[j];
		++j;
	}
	if (i != destsize)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
