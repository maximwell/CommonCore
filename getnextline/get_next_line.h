/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:54:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 04:54:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char    *get_next_line(int fd);


#endif