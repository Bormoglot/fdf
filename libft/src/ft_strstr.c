/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:10:52 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 20:23:12 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the NUL-terminated string 's2' in the
** NUL-terminated string 's1'.
** If 's2' is an empty string, 's1' is returned. If 's2' is not in
** 's1' NULL is returned. Otherwise a pointer to the first character of
** the first occurrence of 's2' is returned.
*/

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!*s1 && !*s2)
		return ((char*)s1);
	if (!*s1 || !*s2)
		return (*s1 ? (char *)s1 : NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0' && s1[i + j] == s2[j])
			++j;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		++i;
	}
	return (NULL);
}
