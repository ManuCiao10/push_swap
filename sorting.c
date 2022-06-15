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



#include "libft/libft.h"
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


void	sorting_3(t_stack *stack)
{
	if (A[0] == 3 && A[1] == 2 && A[2] == 1)
		rotate(stack, STACKA);
	if (A[0] == 1 && A[1] == 3 && A[2] == 2)
		reverse_rotate(stack, STACKA);
	if (A[0] == 2 && A[1] == 1 && A[2] == 3)
		swap(stack, STACKA);
	else if (A[0] == 2 && A[1] == 3 && A[2] == 1)
		reverse_rotate(stack, STACKA);
	else if (A[0] == 3 && A[1] == 1 && A[2] == 2)
		rotate(stack, STACKA);
	else
		swap(stack, STACKA);
}

int	ft_stack_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->a[++i] && stack->a[i + 1])
		if ((stack->a[i]) > (stack->a[i + 1]))
			return (0);
	return (1);
}