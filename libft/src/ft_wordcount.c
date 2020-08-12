/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:25:39 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 22:14:44 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the words in string `s`, separated by character `c`.
*/

size_t	ft_wordcount(char const *s, char c)
{
	size_t	wordcount;

	wordcount = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++wordcount;
		++s;
	}
	return (wordcount);
}
