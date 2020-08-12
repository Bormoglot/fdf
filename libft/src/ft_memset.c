/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:52:52 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/12 21:19:35 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char *ptr;

	ptr = (unsigned char *)dest;
	while (count > 0)
	{
		*ptr = c;
		--count;
		++ptr;
	}
	return (dest);
}
