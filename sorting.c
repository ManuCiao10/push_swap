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


#include "push_swap.h"

// void	sorting_3(t_stack *stack)
// {
// 	if (SA0 > SA1 && SA1 > SA2 && SA0 > SA2)
// 		rotate(stack, STACKA);
// 	if (SA0 < SA1 && SA1 > SA2 && SA0 < SA2)
// 		reverse_rotate(stack, STACKA);
// 	if (SA0 > SA1 && SA1 < SA2 && SA0 < SA2)
// 		swap(stack, STACKA);
// 	else if (SA0 < SA1 && SA1 > SA2 && SA2 < SA0)
// 		reverse_rotate(stack, STACKA);
// 	else if (SA0 > SA1 && SA0 > SA2 && SA2 > SA1)
// 		rotate(stack, STACKA);
// 	else
// 		swap(stack, STACKA);
// }

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

int ft_stack_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->a[++i] && stack->a[i + 1])
		if ((stack->a[i]) > (stack->a[i + 1]))
			return (0);
	return (1);
}