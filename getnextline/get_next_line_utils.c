/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:33 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 17:27:36 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_return_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return ;
	while (!found_newline(*stash) && *readed_ptr > 0)
	{
		*readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if (*readed_ptr < 0)
		{
			free(buf);
			free_stash(*stash);
			*stash = NULL;
			*readed_ptr = -1;
			return ;
		}
		buf[*readed_ptr] = '\0';
		add_to_stash(stash, buf, *readed_ptr);
	}
	free(buf);
}

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	current = stash;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
				return (1);
			i++;
		}
		current = current->next;
	}
	return (0);
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
	{
		free(new_node);
		return ;
	}
	for (int i = 0; i < readed; i++)
		new_node->content[i] = buf[i];
	new_node->content[readed] = '\0';
	new_node->next = NULL;
	if (*stash == NULL)
		*stash = new_node;
	else
	{
		current = *stash;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

void	extract_line(t_list *stash, char **line)
{
	int		len;
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	current = stash;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			len++;
			if (current->content[i++] == '\n')
				break ;
		}
		current = current->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
	current = stash;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			(*line)[j++] = current->content[i++];
			if (current->content[i - 1] == '\n')
				break ;
		}
		current = current->next;
	}
	(*line)[j] = '\0';
}

void	clean_stash(t_list **stash)
{
	t_list	*current;
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*stash == NULL)
		return ;
	current = *stash;
	while (current->content[i] && current->content[i] != '\n')
		i++;
	if (current->content[i] == '\n')
		i++;
	if (current->content[i] == '\0')
	{
		free_stash(*stash);
		*stash = NULL;
		return ;
	}
	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return ;
	temp->content = malloc(sizeof(char) * (ft_strlen(current->content) - i + 1));
	if (temp->content == NULL)
	{
		free(temp);
		return ;
	}
	while (current->content[i])
		temp->content[j++] = current->content[i++];
	temp->content[j] = '\0';
	temp->next = NULL;
	free_stash(*stash);
	*stash = temp;
}

void	free_stash(t_list *stash)
{
	t_list	*temp;

	while (stash)
	{
		temp = stash->next;
		free(stash->content);
		free(stash);
		stash = temp;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}