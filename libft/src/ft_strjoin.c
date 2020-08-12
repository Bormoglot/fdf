/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:32:24 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 21:54:39 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a NUL-terminated string  - a concatenation of 's1'
** and 's2'. Returns NULL if allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			++i;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			++j;
		}
	}
	return (str);
}
