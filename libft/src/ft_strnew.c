/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:52:43 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 21:47:43 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a NUL-terminated string initialized with '\0'.
** Returns NULL if allocation fails.
*/

char	*ft_strnew(size_t size)
{
	if (size + 1 == 0)
		return (NULL);
	return ((char *)ft_memalloc(size + 1));
}
