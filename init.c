/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:48:54 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/14 21:28:35 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//If the Numbers are more than 250 number chunk = 30 else chunk = 15

t_stack *init_stack(int argc, char **argv)
{
	t_stack *stack;
	
	stack = malloc(sizeof(t_stack));
	stack->a = stack_a(argc, argv); //init stack a
	stack->b = ft_calloc(sizeof(int), argc); //calloc stack a
	if (!stack->b)
	{
		free(stack->a);
		print_err("Error stack :(");
	}
	if (argc > 250)
		stack->chunk = 30;
	else
		stack->chunk = 15;
	stack->addchunk = stack->chunk;
	return stack;
}

//Sorting using "applying a permutation" so to have
//and know where the number should be
//overwriting the input value with index number (1, 2, 3...)

int	*stack_a(int argc, char **argv)
{
	int *tmp;
	int i = -1;
	
	tmp = ft_calloc(sizeof(int), argc);
	if (!tmp)
		print_err("Error Stack Malloc");
	i = -1;
	while (argv[++i] != NULL)
		tmp[i] = indexing(argv[i], argv);
	return (tmp);
}

int	indexing(char *number, char **argv)
{
	int i;
	int index = 1;

	i = -1;
	while(argv[++i])
	{
		if(ft_atoi(number) > ft_atoi(argv[i]))
			index++;
	}
	return index;
}