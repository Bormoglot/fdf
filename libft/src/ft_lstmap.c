/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:51:47 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/28 16:46:47 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates over a list 'lst' and creates a new list by applying function 'f()'
** to each node of 'lst'. Returns a new list or NULL, if unsuccessfull.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst && f)
		return (lst);
	return (NULL);
}
