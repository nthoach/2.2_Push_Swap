# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 19:58:59 by nthoach           #+#    #+#              #
#    Updated: 2024/01/29 18:20:24 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Wextra -Werror
PUSH = push_swap

SRCS_PATH = ./
SRCS_FILES = 1_push_swap.c 2_sort_stack_V1.c 3_optimal_rotation.c 4_apply_rotation.c 5_basic_moves.c 6_check_utils.c 7_free_utils.c 8_stack_utils.c 
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIB_PATH = ../libft/
LIB = ../libft/libft.a
HEADER = -I ./ -I ../libft/

all:$(LIB) $(PUSH)

$(LIB):
	@make -C $(LIB_PATH)

$(PUSH):
	@$(CC) $(SRCS) $(LIB) $(HEADER) -o $(PUSH)

clean:
	@make fclean -C $(LIB_PATH)

fclean:clean
	@/bin/rm -f $(PUSH)

re:fclean all