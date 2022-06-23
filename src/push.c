/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 06:01:48 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 12:28:18 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
- pa :push 'a' - take the first element at the top of 'b' and
put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and
put it at the top of 'b'.
*/

void	push(t_stack *stack, int move)
{
	if (move == STACKA && stack->b[0] != 0)
	{
		add(stack->a, stack->b[0]);
		removes(stack->b);
		ft_putstr_fd("pa\n", 1);
	}
	if (move == STACKB && stack->a[0] != 0)
	{
		add(stack->b, stack->a[0]);
		removes(stack->a);
		ft_putstr_fd("pb\n", 1);
	}
}

void	add(int *stack, int dest)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	while (i != 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = dest;
}

void    removes(int *stack)
{
    int i = -1;
    while(stack[++i])
        stack[i] = stack[i + 1];
    stack[i - 1] = 0;
}
