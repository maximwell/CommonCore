/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:00:10 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/04/08 12:30:20 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	append_node(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	parse_loop(t_node **stack, char **args)
{
	int		i;
	long	nb;

	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			exit_error(stack);
		nb = ft_atol(args[i]);
		if (nb < -2147483648 || nb > 2147483647)
			exit_error(stack);
		if (has_duplicate(*stack, (int)nb))
			exit_error(stack);
		append_node(stack, (int)nb);
		i++;
	}
}

void	parse_args(t_node **stack, int argc, char **argv)
{
	char	**args;
	int		should_free;

	should_free = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			exit_error(stack);
		should_free = 1;
	}
	else
		args = &argv[1];
	parse_loop(stack, args);
	if (should_free)
		free_split(args);
}
