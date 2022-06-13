/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:37:55 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/13 06:18:55 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sorting_3(t_stack *stack)
{
	if (SA0 == 3 && SA1 == 2 && SA2 == 1)
		rotate(stack, STACKA);
	if (SA0 == 1 && SA1 == 3 && SA2 == 2)
		reverse_rotate(stack, STACKA);
	if (SA0 == 2 && SA1 == 1 && SA2 == 3)
		swap(stack, STACKA);
	else if (SA0 == 2 && SA1 == 3 && SA2 == 1)
		reverse_rotate(stack, STACKA);
	else if (SA0 == 3 && SA1 == 1 && SA2 == 2)
		rotate(stack, STACKA);
	else
		swap(stack, STACKA);
}
