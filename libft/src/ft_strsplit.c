/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:25:39 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 22:14:44 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a NUL-terminated array of NUL-terminated strings
** obtained by spliting 's' using the character 'c' as a delimiter.
** If the allocation fails the function returns NULL.
*/

static size_t	get_wordlen(char const *s, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (*s != '\0' && *s != c)
	{
		++s;
		++wordlen;
	}
	return (wordlen);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	wordlen;
	size_t	wordcount;
	size_t	i;

	if (!s)
		return (NULL);
	wordcount = ft_wordcount(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (wordcount + 1))))
		return (NULL);
	i = -1;
	while (++i < wordcount && *s)
	{
		while (*s == c)
			++s;
		wordlen = get_wordlen(s, c);
		if (!(arr[i] = ft_strnew(wordlen)))
			return (ft_delptoparr((void **)arr));
		ft_strncpy(arr[i], s, wordlen);
		s += wordlen;
	}
	arr[i] = NULL;
	return (arr);
}
