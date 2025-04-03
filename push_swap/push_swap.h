/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:02:29 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/03/28 01:21:13 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

// Parsing
void	parse_args(t_node **stack, int argc, char **argv);
void	exit_error(t_node **stack);
void	free_stack(t_node **stack);

// Instructions : swap
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

// Instructions : push
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

// Instructions : rotate
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

// Instructions : reverse rotate
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);



#endif
