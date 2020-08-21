/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_and_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <jlavona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2020/08/14 05:00:31 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
** Validates color value.
** Color should be represented as a hex in the form form 0xnnnnnn or
** 0xNNNNNN (totalling 8 chars).
** Returns 1 if true, 0 otherwise.
*/

int			valid_color(const char *str)
{
	int	hex_len;

	hex_len = 0;
	while(*str)
	{
		if ((!ft_isdigit(*str)) && (!ft_strchr("xabcdefABCDEF", *str)))
				return (0);
		str++;
		hex_len++;
	}

	if (hex_len > 0 && hex_len != 8)
		return (0);
	return (1);
}


/*
** Validates elevation and color values.
** Elevation (z) should be a digit (optionally signed).
** If this isn't true, returns -1, otherwise returns an offset, marking
** the beginning of color hex representation.
*/

int			validate_values(const char *str, int offset)
{
	//int		hex_len;
	int		i;

	//hex_len = 0;
	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] == '-' || str[i] == '+')
			++i;
		if (!ft_isdigit(str[i]))
			return (-1);
		++i;
	}
	if (str[i] == ',')
	{
		offset = i + 1;
		if (!(valid_color(&str[i + 1])))
			return (-1);
	}
	return (offset);
}

t_zlist	*new_node(char *str)
{
	t_zlist	*node;
	int		offset;

	offset = 0;
	if (!(node = (t_zlist *)malloc(sizeof(t_zlist))))
		error("Memory allocation failed");
	if ((offset = validate_values(str, offset)) == -1)
		error("Invalid map");
	node->z = ft_atoi(str);
	node->color = offset ? ft_atoi_base(offset + str, 16) : -1;
	node->next = NULL;
	return (node);
}

void	add_node(t_zlist **lst, t_zlist *new)
{
	t_zlist	*node;

	node = new;
	node->next = *lst;
	*lst = new;
}

t_zlist			*get_last_node(t_zlist **lst)
{
	t_zlist *node;

	node = NULL;
	if (lst && *lst)
	{
		node = *lst;
		*lst = (*lst)->next;
	}
	return (node);
}
