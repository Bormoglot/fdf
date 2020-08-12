/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:12:50 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 21:16:28 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes the address of a string, deallocates the memory,
** sets the pointer to NULL
*/

void	ft_strdel(char **as)
{
	if (as)
		ft_memdel((void**)as);
}
