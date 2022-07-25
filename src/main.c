/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:16:29 by eardingh          #+#    #+#             */
/*   Updated: 2022/07/25 09:43:30 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	*split;
	int		split_flag;

	split_flag = 0;
	if (ft_strchr(argv[1], 32) != NULL && argc == 2)
	{
		split = ft_strjoin("push_swap ", argv[1]);
		argc = ft_split_size(split, 32);
		argv = ft_split(split, 32);
		free(split);
		split_flag = 1;
	}
	check_input(argc, argv);
	push_swap(argc, argv);
	if (split_flag == 1)
		ft_free_array(argv);
	return (0);
}

// first argument become [0] and not the title
void	push_swap(int argc, char **argv)
{
	t_stack	*stack;

	stack = init_stack(argc, argv + 1);
	sorting_case(stack, argc);
	free(stack->a);
	free(stack->b);
}

void	sorting_case(t_stack *stack, int number_int)
{
	if (number_int < 4)
		swap(stack, STACKA);
	else if (number_int < 5)
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
- Then you will have 30 number in stack B. 15 first are higher then 15 last.
- When no number to get between those number I do chunk + 15
- Then the loop continue and add 20 to 80 so will add 15 number to 
the start and end of B.
- Then all numbers will be half sort all in  chunk of 15 numbers in B.
- Loop in the first while until there are number in stack-A
- After know which number is best to push bewtween the first and the last
- Push that number 
- While the number to push is not at the first position rotate it
- The first number in stack->b is less thank the size
	/ 2 put the number at the end of the stack
*/

void	ft_sort_big_a_to_b(t_stack *stack, int num)
{
	while (stack->a[0] != 0)
	{
		stack->next = num_smaller(stack->a, stack->chunk, num);
		stack->index = num_index(stack->a, stack->next);
		while (stack->a[0] != stack->next)
		{
			if (stack->index < ft_stack_size(stack->a) / 2)
				rotate(stack, STACKA);
			else
				reverse_rotate(stack, STACKA);
		}
		push(stack, STACKB);
		if (stack->b[0] < num / 2 && ft_stack_size(stack->b) != 1)
			rotate(stack, STACKB);
		if (num_range(stack->a, stack->chunk, num) == 1)
			stack->chunk += stack->addchunk;
	}
	stack->beforelast = 0;
	stack->next = num - 1;
}

/*
1.0-Find the biggest Numbers in the Chunk and push in stack-A
1.1-If you find the biggest Number -1 push it
1.2-Assign beforelast = 1
1.3-Push the biggest Number and do sa
1.4-Put the nextNumber to find -2
1.5-If the Number to push is close to the right part do rrb
1.6-Else just rb to put a the top of the stack
*/

void	ft_sort_big_b_to_a(t_stack *stack)
{
	while (stack->b[0] != 0)
	{
		stack->index = num_index(stack->b, stack->next);
		while (stack->b[0] != stack->next)
		{
			if (stack->b[0] == stack->next - 1)
			{
				push(stack, STACKA);
				stack->beforelast = 1;
			}
			else if (stack->index < ft_stack_size(stack->b) / 2)
				rotate(stack, STACKB);
			else
				reverse_rotate(stack, STACKB);
		}
		push(stack, STACKA);
		if (stack->beforelast == 1)
		{
			stack->next -= 2;
			stack->beforelast = 0;
			swap(stack, STACKA);
		}
		else
			stack->next--;
	}
}

/*
--DEFINITION--
+ stack overflow: when your program want use more space than is available
on the run-time stack --> Special area of compute memory that works on the
LIFO	principle(Last In, First Out).

+ Algorithm 5 Numbers : 
https://medium.com/@jamierobertdawson/
push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
+ Gen_Numbers : https://pinetools.com/es/generador-numeros-aleatorios

void	ft_sort_big_a_to_b(t_stack *stack, int num)
{
	while (stack->a[0] != 0)
	{
		
		stack->next = num_smaller(stack->a, stack->chunk, num);
		printf("stack->next:%d\n", stack->next);
		stack->index = num_index(stack->a, stack->next);
		printf("stack->index:%d\n", stack->index);
		while (stack->a[0] != stack->next)
		{
			if (stack->index < ft_stack_size(stack->a) / 2)
			{
				printf("stack->next:%d\n", stack->next);
				printf("stack->index:%d\n", stack->index);
				rotate(stack, STACKA);
				ft_print_stack(stack);
			}
			else
			{
				printf("stack->next:%d\n", stack->next);
				printf("stack->index:%d\n", stack->index);
				reverse_rotate(stack, STACKA);
				ft_print_stack(stack);
			}
		}
		push(stack, STACKB);
		ft_print_stack(stack);
		if (stack->b[0] < num / 2 && ft_stack_size(stack->b) != 1)
		{
			printf("num:%d\n", num);
			printf("stack->b[0]:%d\n", stack->b[0]);
			rotate(stack, STACKB);
			ft_print_stack(stack);
		}
		if (num_range(stack->a, stack->chunk, num) == 1)
			stack->chunk += stack->addchunk;
	}
	stack->beforelast = 0;
	stack->next = num - 1;
}
*/