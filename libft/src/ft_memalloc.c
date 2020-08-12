/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:23:11 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/24 20:37:57 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates chunk of memory of size 'size' and initializes it with zeros.
** Returns a pointer to allocated memory or NULL if allocation fails.
*/

void	*ft_memalloc(size_t size)
{
	void	*chunk;

	if ((chunk = malloc(size)))
	{
		ft_bzero(chunk, size);
		return (chunk);
	}
	return (NULL);
}
