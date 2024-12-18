/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:53:12 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 01:53:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 

t_list *create_node(int nombre)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
    {
        write(1 ,"Error\n", 6);
        exit(EXIT_FAILURE);
    }
    node->nombre = nombre;
    node->index = 0;
    node->next = NULL;
    return node;
}

t_list *init_stack_a(int argc, char **argv)
{
    t_list *stack = NULL;
    t_list *new_node;
    int i;

    if (argc < 2)
    {
        write(1 ,"Error\n", 6);
        exit(EXIT_FAILURE);
    }
    i = 1; 
    while (i < argc)
    {
        int number = ft_atoi(argv[i]);
        new_node = create_node(number);
        new_node->next = stack; 
        stack = new_node;
        i++;
    }
    return stack;
}