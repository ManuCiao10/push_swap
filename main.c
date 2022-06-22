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
	free(A);
	free(B);
	//ft_print_stack(stack);
}

void sorting_case(t_stack *stack, int number_int)
{
	if (number_int < 5)
		sorting_3(stack);
	else if (number_int < 7)
		ft_sort_five(stack);
	else
	{
		ft_sort_big_a_to_b(stack, number_int);
		ft_sort_big_b_to_a(stack);
	}
}

/*
- For 100 i take 30 number at time and for 500 I take 60 numbers at time
- Then I push the Numbers from 35 to 65 for 100 Numbers
- If the Numbers are less thank half (50) i have even rotate it
- Then you will have 30 number in stack B. 15 first are higher then 15 last.
- When no number to get between those number I do chunk + 15
- Then the loop continue and add 20 to 80 so will add 15 number to the start and end of B.
- Then all numbers will be half sort all in  chunk of 15 numbers in B.
- Loop in the first while until there are number in stack-A
- While th enumber to push is not at the first position rotate it
- The first number in stack->b is less thank the size / 2 put the number at the end of the stack
-
*/

void ft_sort_big_a_to_b(t_stack *stack, int num)
{
	//ft_print_stack(stack);
	while(stack->a[0] != 0)
	{
		stack->next = num_smaller(stack->a, stack->chunk, num);
		//printf("%d\n", stack->next);
		stack->index = num_index(stack->a, stack->next);
		//printf("%d\n", stack->index);
		while (stack->a[0] != stack->next)
		{
			if (stack->index < ft_stack_size(stack->a) / 2)
			{
				rotate(stack, STACKA);
				//ft_print_stack(stack);
				
			}
			else
			{
				reverse_rotate(stack, STACKA);
				//ft_print_stack(stack);
				
			}
		}
		push(stack, STACKB);
		//ft_print_stack(stack);
		if (stack->b[0] < num / 2 && ft_stack_size(stack->b) != 1)
		{
			//printf("-%d-\n", stack->b[0]);
			//printf("*%d*\n", num / 2);
			rotate(stack, STACKB);
			//ft_print_stack(stack);
		}
		if (num_range(stack->a, stack->chunk, num) == 1)
			stack->chunk += stack->addchunk;
	}
	stack->beforelast = 0;
	stack->next = num - 1;
}	

void	ft_sort_big_b_to_a(t_stack *stack)
{
	ft_print_stack(stack);
	while (stack->b[0] != 0)
	{
		stack->index = num_index(stack->b, stack->next);
		printf("index:%d\n", stack->index);
		while (stack->b[0] != stack->next)
		{
			printf("last Number:%d\n", stack->next);
			if (stack->b[0] == stack->next - 1)
			{
				push(stack, STACKA);
				ft_print_stack(stack);
				stack->beforelast = 1;
			}
			else if (stack->index < ft_stack_size(stack->b) / 2)
			{
				rotate(stack, STACKB);
				ft_print_stack(stack);
			}
			else
			{
				reverse_rotate(stack, STACKB);
				ft_print_stack(stack);
			}
		}
		push(stack, STACKA);
		ft_print_stack(stack);
		if (stack->beforelast == 1)
		{
			stack->next -= 2;
			stack->beforelast = 0;
			swap(stack, STACKA);
			ft_print_stack(stack);
		}
		else
			stack->next--;
	}
}

/*
--DEFINITION--

+ stack overflow: when your program want use more space than is available
on the run-time stack --> Special area of compute memory that works on the
LIFO principle(Last In, First Out).

+ algorith : https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
*/