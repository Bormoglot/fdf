/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:39:02 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/25 17:56:25 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	if (s1[0] == '\0')
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j) < len)
			++j;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		++i;
	}
	return (NULL);
}
