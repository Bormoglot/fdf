/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:48:31 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/24 17:46:58 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the last occurrence of c in a NUL-terminated string
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	ch;

	ch = (char)c;
	result = (char*)NULL;
	while (1)
	{
		if (*s == ch)
			result = (char*)s;
		if (*s == '\0')
			return (result);
		++s;
	}
}
