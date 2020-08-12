/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:09:14 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/24 21:42:17 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographically compares strings 's1' and 's2'.
** Returns 0 if strings are equal, int > 0 if 's1' > 's2',
** int < 0 if 's1' < 's2'
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
