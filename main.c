/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:16:29 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/13 16:06:28 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"


int main(int argc, char **argv)
{
	check_input(argc, argv); //check input
	push_swap(argc, argv); //init the stack
	return 0;
}

void push_swap(int argc, char **argv)
{
	t_stack *stack;

	stack = init_stack(argc, argv + 1); //first argument become [0] and not the title
	sorting_case(stack, argc - 1);
	ft_print_stack(stack);
}

void	sorting_case(t_stack *stack, int number_int)
{
	if(number_int <= 3)
		sorting_3_test(stack);
	// else if(number_int <= 5)
	// 	sorting_5(stack);
	// else
	// 	sorting_long(stack);
}

void	sorting_5(t_stack *stack)
{
	int i = 0;
	while(stack->a[i] != 0)
		i++;
	while(i >= 4)
	{
		push(stack, STACKB);
		i--;
	}
	sorting_3(stack);
	rotate(stack, STACKA);
}

/*
--DEFINITION--

+ stack overflow: when your program want use more space than is available
on the run-time stack --> Special area of compute memory that works on the
LIFO principle(Last In, First Out).
+ algorith : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

--TODO--
° Print the Stack in butterfly position left and rigt side.
° Add git commit and push in the Make-File
*/