/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximmarhic <maximmarhic@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:02:11 by maximmarhic       #+#    #+#             */
/*   Updated: 2025/03/26 03:21:50 by maximmarhic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	result = 0;
	int		sign = 1;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

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

void	parse_args(t_node **stack, int argc, char **argv)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			exit_error(stack);
		nb = ft_atol(argv[i]);
		if (nb < -2147483648 || nb > 2147483647 || has_duplicate(*stack, (int)nb))
			exit_error(stack);
		append_node(stack, (int)nb);
		i++;
	}
}
