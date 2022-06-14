/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:16:29 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/14 16:36:55 by eardingh         ###   ########.fr       */
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
	//free(A);
	//free(B);
	ft_print_stack(stack);
}

void	sorting_case(t_stack *stack, int number_int)
{
	if(number_int <= 3)
		sorting_3(stack);
	else if(number_int <= 5)
		sorting_5(stack);
	// else
	// 	sorting_long(stack);
}

void	sorting_5(t_stack *stack)
{
	while(stack->a[0] != 1)
		rotate(stack,STACKA);
	push(stack, STACKB);
	while(stack->a[0] != 2)
		rotate(stack,STACKA);
	push(stack, STACKB);
	sorting_3(stack);
	push(stack, STACKA);
	push(stack, STACKA);
}

int find_min_a(t_stack *stack)
{
	int i = 0;

	while(stack->a[i] != 1)
		i++;
	return i;
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