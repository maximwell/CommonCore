/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:33 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 23:30:41 by mmarhic          ###   ########.fr       */
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
