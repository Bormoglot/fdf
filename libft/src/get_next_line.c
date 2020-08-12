/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlavona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:57 by jlavona           #+#    #+#             */
/*   Updated: 2019/10/28 11:00:06 by jlavona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tries to find a node (of a linked list) associated with a file descriptor
** 'fd'. If there is no list - creates it. If there is no such node - creates
** it.
*/

t_list	*get_node(const int fd)
{
	static t_list	*list;
	t_list			*node;
	t_list			*new_node;

	if (list == NULL)
	{
		if ((list = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		list->content_size = fd;
		return (list);
	}
	node = list;
	while ((node->next != NULL) && ((int)(node->content_size) != fd))
		node = node->next;
	if ((int)(node->content_size) == fd)
		return (node);
	else
	{
		if ((new_node = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		node->next = new_node;
		new_node->content_size = fd;
		return (new_node);
	}
}

/*
** Reads from file descriptor
*/

int		read_from_fd(t_list *node)
{
	char	buffer[BUFF_SIZE + 1];
	int		file_descriptor;
	int		bytes_read;
	char	*joined_string;

	file_descriptor = node->content_size;
	bytes_read = read(file_descriptor, buffer, BUFF_SIZE);
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
	{
		return (GNL_EOF);
	}
	if (node->content == NULL)
	{
		if ((node->content = ft_strdup(buffer)) == NULL)
			return (GNL_ERROR);
	}
	else
	{
		if ((joined_string = ft_strjoin(node->content, buffer)) == NULL)
			return (GNL_ERROR);
		ft_strdel((char **)&(node->content));
		node->content = joined_string;
	}
	return (GNL_OK);
}

int		save_line(t_list *node, char *newline_position_ptr, char **line)
{
	char	*line_text;
	char	*remainder_text;

	*newline_position_ptr = '\0';
	line_text = ft_strdup(node->content);
	if (line_text == NULL)
		return (GNL_ERROR);
	else
	{
		*line = line_text;
	}
	remainder_text = ft_strdup(newline_position_ptr + 1);
	if (remainder_text == NULL)
		return (GNL_ERROR);
	else
	{
		ft_strdel((char **)&(node->content));
		node->content = remainder_text;
		return (GNL_OK);
	}
}

int		parse_content(t_list *node, char **line)
{
	char	*newline_position_ptr;
	int		status;

	if ((node->content == NULL) && ((status = read_from_fd(node)) != GNL_OK))
		return (status);
	if ((newline_position_ptr = ft_strchr(node->content, '\n')))
		return (status = save_line(node, newline_position_ptr, line));
	else
	{
		while ((status = read_from_fd(node)) == GNL_OK)
		{
			if ((newline_position_ptr = ft_strchr(node->content, '\n')))
				return (status = save_line(node, newline_position_ptr, line));
		}
		if (status == GNL_EOF)
		{
			if (ft_strlen(node->content) == 0)
				return (GNL_EOF);
			if ((*line = ft_strdup(node->content)) == NULL)
				return (GNL_ERROR);
			ft_strdel((char **)&(node->content));
			return (GNL_OK);
		}
		return (status);
	}
}

int		get_next_line(const int fd, char **line)
{
	t_list	*node;
	int		status;

	if (fd < 0 || (line == NULL) || (read(fd, NULL, 0) == -1))
	{
		status = GNL_ERROR;
		return (status);
	}
	node = get_node(fd);
	if (node == NULL)
	{
		status = GNL_ERROR;
		return (status);
	}
	status = parse_content(node, line);
	return (status);
}
