/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:36:24 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/04/08 16:38:00 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_radix(t_node **a, t_node **b)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = get_stack_size(*a);
	assign_index(*a);
	while (!is_sorted(*a))
	{
		j = 0;
		while (j++ < size)
		{
			if (*a && (((*a)->index >> i) & 1))
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		sort_radix(a, b);
}
