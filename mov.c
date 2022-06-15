/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:42:03 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 12:16:53 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
STACKA 	  --> swap the first 2 elements at the top of stack 'a';
STACKB 	  --> swap the first 2 elements at the top of stack 'b';
BOTHSTACK -->sa and sb at the same time.

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
*/

void	swap(t_stack *stack, int set)
{
	int	temp;

	if (set == STACKA || set == BOTHSTACK)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	if (set == STACKB || set == BOTHSTACK)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
	if (set == STACKA)
		ft_putstr_fd("sa\n", 1);
	if (set == STACKB)
		ft_putstr_fd("sb\n", 1);
	if (set == BOTHSTACK)
		ft_putstr_fd("ss\n", 1);
}

/*
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
*/

void     rotate(t_stack *stack, int move)
{
    int	i;
	int	temp;

	i = -1;
	if (move == STACKA || move == BOTHSTACK)
	{
		temp = stack->a[0];
		while (stack->a[++i + 1])
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = temp;
	}
	if (move == STACKB || move == BOTHSTACK)
	{
		i = -1;
		temp = stack->b[0];
		while (stack->b[++i + 1])
			stack->b[i] = stack->b[i + 1];
		stack->b[i] = temp;
	}
	if (move == STACKA)
		ft_putstr_fd("ra\n", 1);
	if (move == STACKB)
		ft_putstr_fd("rb\n", 1);
	if (move == BOTHSTACK)
		ft_putstr_fd("rr\n", 1);
}

/*
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.
*/

void    reverse_rotate(t_stack *stack, int move)
{
    if(move == STACKA || move == BOTHSTACK)
        reverse(stack->a);
    if(move == STACKB || move == BOTHSTACK)
        reverse(stack->b);
    if (move == STACKA)
		ft_putstr_fd("rra\n", 1);
	if (move == STACKB)
		ft_putstr_fd("rrb\n", 1);
	if (move == BOTHSTACK)
		ft_putstr_fd("rrr\n", 1);
}

void    reverse(int *stack)
{
    int tmp;
    int i;

    i = 0;
    while(stack[i + 1])
        i++;
    tmp = stack[i];
    while(i > 0)
    {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[i] = tmp;
}
