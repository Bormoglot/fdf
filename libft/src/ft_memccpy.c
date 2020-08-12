/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:16:48 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/15 20:29:11 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)dest;
	while (n > 0)
	{
		*ptr = *((unsigned char *)src);
		if (*ptr == (unsigned char)c)
		{
			++ptr;
			return ((void*)ptr);
		}
		++ptr;
		++src;
		--n;
	}
	return (NULL);
}
