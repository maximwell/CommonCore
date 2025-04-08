/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:43:02 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/04/08 16:43:05 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

/* ---------- STRUCTURE ---------- */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* ---------- PARSING ---------- */

void	parse_args(t_node **stack, int argc, char **argv);
int		is_number(char *str);
long	ft_atol(const char *str);
int		has_duplicate(t_node *stack, int value);
void	append_node(t_node **stack, int value);
void	free_split(char **split);
void	free_stack(t_node **stack);
void	exit_error(t_node **stack);

/* ---------- INSTRUCTIONS ---------- */

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* ---------- TRI ---------- */

void	sort_two(t_node **a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	sort_stack(t_node **a, t_node **b);
void	sort_radix(t_node **a, t_node **b);
int		is_sorted(t_node *stack);

/* ---------- OUTILS ---------- */

int		get_stack_size(t_node *stack);
void	assign_index(t_node *stack);

#endif
