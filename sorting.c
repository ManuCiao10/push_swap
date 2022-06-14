/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:37:55 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/14 11:45:56 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sorting_3(t_stack *stack)
{
	if (SA0 > SA1 && SA1 > SA2 && SA0 > SA2)
		rotate(stack, STACKA);
	if (SA0 < SA1 && SA1 > SA2 && SA0 < SA2)
		reverse_rotate(stack, STACKA);
	if (SA0 > SA1 && SA1 < SA2 && SA0 < SA2)
		swap(stack, STACKA);
	else if (SA0 < SA1 && SA1 > SA2 && SA2 < SA0)
		reverse_rotate(stack, STACKA);
	else if (SA0 > SA1 && SA0 > SA2 && SA2 > SA1)
		rotate(stack, STACKA);
	else
		swap(stack, STACKA);
}
