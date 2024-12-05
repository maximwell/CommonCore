/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarhic <mmarhic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:43 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 23:15:00 by mmarhic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			lettre;
	struct s_list	*suivant;
}					t_list;

t_list				*ft_lstnew(char lettre);
char				*get_next_line(int fd);
char				*list_to_ptr(t_list **lst);
void				fill_list(t_list **lst, t_list *dernier, int fd);
int					obtenir_nl(t_list *lst);
int					obtenir_longeur(t_list *lst, int i);
t_list				*ft_lstlast(t_list *lst);
void				free_list(t_list **lst);
#endif