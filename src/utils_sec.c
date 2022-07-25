/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 07:50:13 by eardingh          #+#    #+#             */
/*   Updated: 2022/07/25 09:45:09 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("\033[0;32mSTACK A  \033[0;37m");
	while (stack->a[i] != 0)
	{
		printf("[\033[0;36m%d\033[0;37m]", stack->a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("\033[0;33mSTACK B  \033[0;37m");
	while (stack->b[i] != 0)
	{
		printf("[\033[0;36m%d\033[0;37m]", stack->b[i]);
		i++;
	}
	printf("\n");
}

/*
You are looking for number 40 to 60
Then « i » will stop to first number between 40 and 60
Then « j » will start and the end of the stack
Then you need to check if « i » or « j » will be faster to get
	//printf("first:%d\n", first);
	//printf("last:%d\n", last);
	//printf("NUM:%d\n", num);
*/

int	num_smaller(int *stack, int chunk, int num)
{
	int	i;
	int	j;
	int	first;
	int	last;

	i = 0;
	while (stack[i] <= ((num / 2) - chunk) || stack[i] >= ((num / 2) + chunk))
		i++;
	first = stack[i];
	j = ft_stack_size(stack) - 1;
	while (stack[j] <= ((num / 2) - chunk) || stack[j] >= ((num / 2) + chunk))
		j--;
	last = stack[j];
	if (num - j < i)
		return (last);
	else
		return (first);
}

int	ft_stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i);
}

// check if the Number are in The range
int	num_range(int *stack, int chunk, int num)
{
	int	i;

	i = -1;
	while (stack[++i])
	{
		if ((stack[i] < (num / 2) + chunk) && (stack[i] > (num / 2) - chunk))
			return (0);
	}
	return (1);
}

int	num_index(int *stack, int num)
{
	int	i;

	i = -1;
	while (stack[++i])
	{
		if (stack[i] == num)
			return (i);
	}
	return (0);
}
