/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:30:35 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/14 20:55:55 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_string;
	char	*ptr;

	if (s
			&& f
			&& (len = ft_strlen((char*)s))
			&& (new_string = (char*)malloc(sizeof(char) * (len + 1)))
)
	{
		ptr = new_string;
		while (len > 0)
		{
			*ptr = f(*s);
			--len;
			++ptr;
			++s;
		}
		*ptr = '\0';
		return (new_string);
	}
	return ((char*)NULL);
}
