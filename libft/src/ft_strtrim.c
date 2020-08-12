/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:31:29 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 22:18:55 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a copy of the string 's' without  whitespaces (' ',
** '\n', '\t') at the beginning and at the end of the string.
** If 's' has no whitespaces, returns a copy of s. If the allocation fails
** returns NULL.
*/

static int	ft_iswhitespace(char c)
{
	return (c == '\t' || c == '\n' || c == ' ');
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_iswhitespace(s[i]))
		++i;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[j]))
		--j;
	if ((str = ft_strnew(j - i + 1)))
		ft_strncpy(str, &s[i], j - i + 1);
	return (str);
}
