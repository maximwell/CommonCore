/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 04:45:00 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/04/08 12:21:50 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	get_index(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

static void	push_min(t_node **a, t_node **b)
{
	int	min;
	int	pos;
	int	size;

	min = get_min(*a);
	pos = get_index(*a, min);
	size = get_stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
	pb(a, b);
}

void	sort_five(t_node **a, t_node **b)
{
	int	pushed;

	pushed = 0;
	while (get_stack_size(*a) > 3)
	{
		push_min(a, b);
		pushed++;
	}
	sort_three(a);
	if (pushed == 2 && *b && (*b)->next && (*b)->value < (*b)->next->value)
		sb(b);
	if (*b)
		pa(a, b);
	if (*b)
		pa(a, b);
}
