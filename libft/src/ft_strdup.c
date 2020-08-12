/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:34:26 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/24 12:57:44 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_copy;

	len = ft_strlen((char*)s);
	if ((s_copy = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_memcpy(s_copy, (void*)s, len + 1);
	return (s_copy);
}
