# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:10:06 by eardingh          #+#    #+#              #
#    Updated: 2022/07/21 08:02:50 by eardingh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = 		./libft/libft.a
LIBFT_PATH = 	./libft

CC = 			gcc -o $(NAME)
NAME =			push_swap
CFLAGS = 		-Wall -Werror -Wextra -g
RM = 			rm -f

OBJS		= 	$(SRCS:%.c=%.o)

SRCS = 			src/main.c src/utils.c src/check_input.c src/init.c src/mov.c src/sorting.c src/push.c src/utils_sec.c
	
all: $(NAME)
	
${NAME}: 
	-@$(MAKE) -C $(LIBFT_PATH)
	-@$(CC) $(CFLAGS) $(SRCS) $(LIBFT)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@$(RM) $(NAME) $(LIBFT)

re: fclean $(NAME)
