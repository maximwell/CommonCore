/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: max <max@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 04:58:14 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 00:09:48 by max              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// trouver si c'est un long ou un int

// ajouter 2 atoi

// ajouter le radix sort

typedef struct s_list
{
	int				index;
	int				nombre;
	struct s_list	*next;
}					t_list;

t_list *create_node(int nombre);
t_list *init_stack_a(int argc, char **argv);
int ft_atoi(const char *str);



#endif