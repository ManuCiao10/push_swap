/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:19:25 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/15 12:07:38 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_input(int argc, char **argv)
{
	if (argc < 2)
		print_err("Usage: ./push_swap [number]\n");
	check_duplicate(argv);
	check_number(argv);
	check_overflow(argv);
	if (ft_check_sorted(argv))
		exit(0);
}

void	check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j++]) == 0)
			{
				print_err("Error Duplicate\n");
			}
		}
		i++;
	}
}

void	check_number(char **argv)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 1;
	array = argv[j];
	while (array)
	{
		i = 0;
		while (array[i])
		{
			if(array[i] == '-')
				i++;
			if (!ft_isdigit(array[i]))
				print_err("Error not a number\n");
			i++;
		}
		j++;
		array = argv[j];
	}
}

void	check_overflow(char **argv)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num <= INT_MIN || num >= INT_MAX)
			print_err("Error overflow\n");
		i++;
	}
}

int	ft_check_sorted(char **argv)
{
	int i;

	i = 0;
	while (argv[++i] && argv[i + 1])
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
	return (1);
}