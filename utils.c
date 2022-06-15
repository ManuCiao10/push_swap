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

#include "libft/libft.h"
#include "push_swap.h"

void 	print_err(char *message)
{
	write(2, message, ft_strlen(message));
	exit(0);
}

int 	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

long 	ft_atol(const char *s)
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

int 	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	printf("\033[0;35mSTACK A  \033[0;37m\n");
	while (stack->a[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]\n", stack->a[i]);
	printf("\n");
	i = -1;
	printf("\033[0;33mSTACK B  \033[0;37m\n");
	while (stack->b[++i] != 0)
		printf("[\033[0;36m%03d\033[0;37m]\n", stack->b[i]);
	printf("\n");
}
 