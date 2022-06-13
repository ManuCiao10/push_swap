/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 09:48:54 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/13 16:49:34 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack *init_stack(int argc, char **argv)
{
	t_stack *stack;
	
	stack = malloc(sizeof(t_stack));
	stack->a = stack_a(argc, argv); //init stack a
	stack->b = ft_calloc(sizeof(int), argc); //malloc stack a
	if (!stack->b)
	{
		free(stack->a);
		print_err("Error stack :(");
	}
	return stack;
}

//Sorting using "applying a permutation" so to have
//and know where the number should be
//overwriting the input value with index number (1, 2, 3...)

int	*stack_a(int argc, char **argv)
{
	int *tmp;
	int i = -1;
	
	tmp = malloc(sizeof(int) * argc);
	if(!tmp)
		print_err("Error Stack Malloc");
	while(argv[++i] != NULL)
	{
		tmp[i] = indexing(argv[i], argv);
	}
	return tmp;
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