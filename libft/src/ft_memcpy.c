/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:39:11 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 23:22:38 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dest'.
** If 'src' and 'dest' overlap, behavior is undefined.
*/

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	return (ft_memmove(dest, src, n));
}
