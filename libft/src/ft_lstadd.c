/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:48:12 by jlavona           #+#    #+#             */
/*   Updated: 2019/09/27 20:42:28 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds new node 'new' at the beginning of the list
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*node;

	node = new;
	node->next = *alst;
	*alst = new;
}
