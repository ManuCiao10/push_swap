/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:04:52 by eardingh          #+#    #+#             */
/*   Updated: 2022/06/14 13:27:19 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BOTHSTACK 4

/* Stack A */

# define SA0 stack->a[0]
# define SA1 stack->a[1]
# define SA2 stack->a[2]
# define STACKA 2

/* Stack B */

# define SB0 stack->b[0]
# define SB1 stack->b[1]
# define SB2 stack->b[2]
# define STACKB 3

/* struct */

typedef struct s_stack
{
	int	*a; //stack a
	int	*b; //stack b
}				t_stack;

/* Push_swap */

void	print_err(char *message);
int		main(int argc, char **argv);
void	ft_print_stack(t_stack *stack);

/* Input */

void	check_input(int argc, char **argv);
void	check_duplicate(char **argv);
void	check_number(char **argv);
void	check_overflow(char **argv);
int		ft_check_sorted(char **argv);

/* Utils */

long 	ft_atol(const char *s);
int 	ft_strcmp(char *s1, char *s2);
int 	ft_isspace(int c);

/* Stack */

t_stack *init_stack(int argc, char **argv);
void 	push_swap(int argc, char **argv);
int		*stack_a(int argc, char **argv);
int		indexing(char *number, char **argv);
void	sorting_case(t_stack *stack, int number_int);

/* Move */

void	swap(t_stack *stack, int move);
void    reverse_rotate(t_stack *stack, int move);
void    reverse(int *stack);
void	sorting_3(t_stack *stack);
void	sorting_5(t_stack *stack);
void	push(t_stack *stack, int move);
void    rotate(t_stack *stack, int move);
void	add(int *stack, int dest);
void    removes(int *stack);
int		ft_stack_sorted(t_stack *stack);
int find_min_a(t_stack *stack);
void	push_min(t_stack *stack, int move, int min);


#endif