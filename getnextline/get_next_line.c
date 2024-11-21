/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:12 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 04:54:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static t_list   *stash;
    char            *line;
    int             readed;

    stash = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0 )
        return(NULL);
    readed = 1;
    line = NULL;
    // Lire de fd et stock dans list (stash en gros)
    read_and_stash(fd, &stash, &readed);
    if (stash == NULL)
        return(NULL);
    // extraire mon contenue de stash vers line
    // free stash en gros de gros 'facile'
    return(line);
}

void    read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
    char    *buf;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
        return();
    while (!found_newline(*stash) && *readed_ptr != 0)
    {
        *readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
        if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
        {
            free(buf);
            return;
        }
        buf[*readed_ptr] = '\0';
        add_to_stash(stash, buf, *readed_ptr);
    }
}

int found_newline(t_list *stash)
{
    int     i;
    t_list  *current;

    if (stash == NULL)
        return(0);
    current = ft_lst_get_last(stash);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return(1);
        i++;
    }
    return(0);
}

t_list  *ft_lst_get_last()
{
    t_list  *current;
    -*-*
    current = stash;
    while (current && current->next)
        current = current->next;
    return(current);
}

void add_to_stash(t_list **stash, char *buf, int readed)
{
    int     i;
    t_list  *current;
    t_list  *new_node;

    new_node = malloc(sizeof(t_list));
    if (new_node == NULL)
        return;
    new_node->next = NULL;
    new_node->content = malloc(sizeof(char) * (readed + 1));
    if (new_node->content == NULL)
        return;
    i = 0;
    while(buf[i] && i < readed)
    {
        new_node->content[i] = buf[i];
        i++;
    }
    new_node->content[i] = '\0';
    if (*stash == NULL)
    {
        *stash = new_node;
        return;
    }
    current = ft_lst_get_last(*stash);
    last->next = new_node;
}