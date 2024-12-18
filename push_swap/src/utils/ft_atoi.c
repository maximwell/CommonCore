/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 02:22:05 by marvin            #+#    #+#             */
/*   Updated: 2024/12/18 02:22:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// atoi moddé prends en compte les limites
// stop le program au moment ou ca overflow en gros

int ft_atoi(const char *str)
{
    long res = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        if (res * sign > INT_MAX || res * sign < INT_MIN)
        {
            write(1 ,"Error\n", 6);
            exit(EXIT_FAILURE);
        }
        str++;
    }
    if (*str != '\0')
    {
        write(1 ,"Error\n", 6);
        exit(EXIT_FAILURE);
    }
    return ((int)(res * sign));
}