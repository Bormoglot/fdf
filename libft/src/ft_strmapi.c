/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:47:31 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/15 21:55:50 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*new_string;
	char			*ptr;

	if (s
			&& f
			&& (len = ft_strlen((char*)s))
			&& (new_string = (char*)malloc(sizeof(char) * (len + 1)))
)
	{
		i = 0;
		ptr = new_string;
		while (len > 0)
		{
			*ptr = f(i, *s);
			--len;
			++ptr;
			++s;
			++i;
		}
		*ptr = '\0';
		return (new_string);
	}
	return ((char*)NULL);
}
