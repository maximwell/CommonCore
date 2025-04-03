/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:33:45 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/03/27 02:33:49 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
