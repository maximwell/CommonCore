/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:33 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 21:37:02 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char lettre)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->lettre = lettre;
	lst->suivant = NULL;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->suivant)
		lst = lst->suivant;
	return (lst);
}

int	obtenir_nl(t_list *lst)
{
	while (lst && lst->lettre != '\n')
		lst = lst->suivant;
	return (lst != NULL);
}

int	obtenir_longeur(t_list *lst, int i)
{
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		if (lst->lettre == '\n')
			return (i);
		lst = lst->suivant;
	}
	return (i);
}

void	fill_list(t_list **lst, t_list *dernier, int fd)
{
	char	*buffer;
	int		bytes_lus;
	int		i;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
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
	free(buffer);
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