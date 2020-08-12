/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:34:35 by jlavona           #+#    #+#             */
/*   Updated: 2019/10/27 17:57:10 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a new node. The variables 'content' and
** 'content_size' of the new node are initialized by copy of the parameters
** of the function. If the parameter 'content' is NULL, the variable 'content'
** is initialized to NULL and the variable 'content_size' is initialized
** to 0 even if the parameter 'content_size' isn’t. The variable 'next' is
** initialized to NULL. If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		if (!(node->content = malloc(sizeof(size_t) * content_size)))
			return (NULL);
		ft_memcpy(node->content, (void *)content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
