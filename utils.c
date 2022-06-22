/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:57:44 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 11:50:57 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_err(char *message)
{
	write(2, message, ft_strlen(message));
	exit(0);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

long ft_atol(const char *s)
{
	int i;
	long res;
	long coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}

int ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void ft_print_stack(t_stack *stack)
{
	int i;

	i = 0;
	ft_printf("\033[0;32mSTACK A  \033[0;37m");
	while (stack->a[i] != 0)
	{
		ft_printf("[\033[0;36m%d\033[0;37m]", stack->a[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("\033[0;33mSTACK B  \033[0;37m");
	while (stack->b[i] != 0)
	{
		ft_printf("[\033[0;36m%d\033[0;37m]", stack->b[i]);
		i++;
	}
	ft_printf("\n");
}

int ft_last(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	return (stack[i - 1]);
}

int ft_stack_size(int *stack)
{
	int i;

	i = 0;
	while (stack[i] != 0)
		i++;
	return (i);
}

int num_range(int *stack, int chunk, int num)
{
	int i = -1;
	// check if the Number are in The range
	while (stack[++i])
	{
		if ((stack[i] < (num / 2) + chunk) && (stack[i] > (num / 2) - chunk))
			return 0;
	}
	return 1;
}

int num_index(int *stack, int num)
{
	int i = -1;

	while (stack[++i])
	{
		if (stack[i] == num)
			return i;
	}
	return 0;
}

/*
You are looking for number 40 to 60
Then you need to find where the closest number is
Then « i » will stop to first number between 40 and 60
Then « j » will start and the end of the stack and stop when he find a number between 40 and 60
Then you need to check if « i » or « j » will be faster to get
*/

int num_smaller(int *stack, int chunk, int num)
{
	int i = 0;
	int j;
	int first;
	int last;

	while (stack[i] <= ((num / 2) - chunk) || stack[i] >= ((num / 2) + chunk))
		i++;
	first = stack[i];
	j = ft_stack_size(stack) - 1;
	while (stack[j] <= ((num / 2) - chunk) || stack[j] >= ((num / 2) + chunk))
		j--;
	last = stack[j];
	if (num - j < i)
		return last;
	else
		return first;
}