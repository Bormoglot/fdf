/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delptoparr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:01:19 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/26 20:10:35 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** A comment! Well formatted.
*/

void	*ft_delptoparr(void **arr)
{
	while (arr)
	{
		ft_memdel(arr);
		++arr;
	}
	free(arr);
	return (NULL);
}
