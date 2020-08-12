/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:30:13 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 22:09:41 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 or 0 according to if strings are identical or not
*/

int	ft_strequ(char const *s1, char const *s2)
{
	return (s1 && s2 && !(ft_strcmp(s1, s2)));
}
