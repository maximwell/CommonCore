/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:18:40 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/03/26 15:20:31 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // à enlever après les tests

void	print_stack(t_node *stack, char *name)
{
	printf("Stack %s:\n", name);
	while (stack)
	{
		printf("  %d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a = NULL;

	if (argc < 2)
		return (0);
	parse_args(&stack_a, argc, argv);

	printf("Avant sa:\n");
	print_stack(stack_a, "A");

	sa(&stack_a);

	printf("Après sa:\n");
	print_stack(stack_a, "A");

	free_stack(&stack_a);
	return (0);
}

