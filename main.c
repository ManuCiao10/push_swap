/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:16:29 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 12:33:23 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	check_input(argc, argv); // check input
	push_swap(argc, argv);	 // init the stack
	return 0;
}

void push_swap(int argc, char **argv)
{
	t_stack *stack;

	stack = init_stack(argc, argv + 1); // first argument become [0] and not the title
	sorting_case(stack, argc);
	// free(A);
	// free(B);
	ft_print_stack(stack);
}

void sorting_case(t_stack *stack, int number_int)
{
	if (number_int < 5)
		sorting_3(stack);
	else if (number_int < 7)
		ft_sort_five(stack);
	// else
	// 	sorting_long(stack);
}

// take out the tiny Number 1 and 2
// later on call sort_three

void ft_sort_five(t_stack *stack)
{
	//ft_print_stack(stack);
	while (stack->a[3] != 0) //when there is 3 numbers
	{
		if(stack->a[0] < 3)
		{
			push(stack, STACKB);
			//ft_print_stack(stack);
		}
		else
		{
			rotate(stack, STACKA);
			//ft_print_stack(stack);
		}
	}
	sorting_3(stack);
	if (stack->b[0] < stack->b[1])
		swap(stack, STACKB);
	push(stack, STACKA);
	push(stack, STACKA);
}



/*
--DEFINITION--

+ stack overflow: when your program want use more space than is available
on the run-time stack --> Special area of compute memory that works on the
LIFO principle(Last In, First Out).
+ algorith : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

--TODO--
° Working with 100 numbers and with 500
*/