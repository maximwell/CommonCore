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
    // extraire mon contenue de stash vers line
    // free stash en gros de gros 'facile'

    





}