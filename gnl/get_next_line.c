/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:12 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 23:26:57 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_list(&lst, ft_lstlast(lst), fd);
	return (list_to_ptr(&lst));
}

// Remplit une liste avec les données lues depuis un fichier.

void	fill_list(t_list **lst, t_list *dernier, int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_lus;
	int		i;

	while (!obtenir_nl(*lst))
	{
		bytes_lus = read(fd, buffer, BUFFER_SIZE);
		if (bytes_lus <= 0)
			break ;
		i = 0;
		if (!*lst)
			*lst = ft_lstnew(buffer[i++]);
		if (!dernier)
			dernier = *lst;
		while (i < bytes_lus)
		{
			dernier->suivant = ft_lstnew(buffer[i]);
			dernier = dernier->suivant;
			i++;
		}
	}
	if (bytes_lus == -1)
		free_list(lst);
}

void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->suivant;
		free(*lst);
		*lst = tmp;
	}
}

char	*list_to_ptr(t_list **lst)
{
	char	*ligne;
	t_list	*tmp;
	int		longeur;
	int		i;

	if (*lst == NULL)
		return (NULL);
	longeur = obtenir_longeur(*lst, 0);
	ligne = (char *)malloc(sizeof(char) * (longeur + 1));
	i = 0;
	while (i < longeur)
	{
		ligne[i] = (*lst)->lettre;
		tmp = *lst;
		*lst = (*lst)->suivant;
		free(tmp);
		i++;
	}
	ligne[longeur] = '\0';
	return (ligne);
}
