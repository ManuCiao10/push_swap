# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:10:06 by eardingh          #+#    #+#              #
#    Updated: 2022/06/14 11:41:34 by eardingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = 		./libft/libft.a
LIBFT_PATH = 	./libft
PRINT_PATH = 	./ft_printf
PRINT = 		./ft_printf/libftprintf.a

CC = 			gcc -o $(NAME)
NAME =			push_swap
CFLAGS = 		-Wall -Werror -Wextra -g
RM = 			rm -f

OBJS		= 	$(SRCS:%.c=%.o)

SRCS = 			main.c utils.c check_input.c init.c mov.c sorting.c push.c
	
all: $(NAME)
	
${NAME}: 
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(MAKE) -C $(PRINT_PATH)
	-@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(PRINT)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) $(PRINT)

re: fclean $(NAME)
