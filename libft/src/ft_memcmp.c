/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:57:33 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/25 14:07:37 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares byte string 'str1' against 'str2'. Both are assumed to be 'n'
** bytes long.
** Returns 0 if identical, otherwise returns the difference between the
** first two differing bytes.
*/

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = (const unsigned char *)str1;
	ptr2 = (const unsigned char *)str2;
	while (n > 1 && *ptr1 == *ptr2)
	{
		--n;
		++ptr1;
		++ptr2;
	}
	return ((int)(*ptr1 - *ptr2));
}
