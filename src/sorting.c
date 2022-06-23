/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:37:55 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 12:28:51 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Sorting 3 Numbers i basically Hard-code all the possibility
*/

void sorting_3(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		rotate(stack, STACKA);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
		reverse_rotate(stack, STACKA);
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2])
		swap(stack, STACKA);
	else if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
		reverse_rotate(stack, STACKA);
	else if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
		rotate(stack, STACKA);
}

// take out the tiny Number 1 and 2
// later on call sort_three

void ft_sort_five(t_stack *stack)
{
	while (stack->a[3] != 0) // when there are 3 numbers
	{
		if (stack->a[0] < 3)
			push(stack, STACKB);
		else
			rotate(stack, STACKA);
	}
	sorting_3(stack);
	if (stack->b[0] < stack->b[1])
		swap(stack, STACKB);
	push(stack, STACKA);
	push(stack, STACKA);
}

int ft_stack_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->a[++i] && stack->a[i + 1])
		if ((stack->a[i]) > (stack->a[i + 1]))
			return (0);
	return (1);
}