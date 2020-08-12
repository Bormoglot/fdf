/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:44:34 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/28 16:55:55 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes an address of a pointer to a node 'alst', frees the memory of node
** contents using function 'del()', then frees the memory for node itself.
** Sets the pointer to the freed node to NULL.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
		return ;
}
