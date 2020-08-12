/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:45:28 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 23:18:23 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'len' bytes from string 'src' to string 'dest'.
** Returns 'dest'.
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d_ptr;
	char	*s_ptr;

	if (!src && !dest)
		return (dest);
	if (src == dest)
		return (dest);
	d_ptr = (char *)dest;
	s_ptr = (char *)src;
	if (src > dest)
	{
		while (len--)
			*d_ptr++ = *s_ptr++;
		return (dest);
	}
	d_ptr += len;
	s_ptr += len;
	while (len--)
		*--d_ptr = *--s_ptr;
	return (dest);
}
