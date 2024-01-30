#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 13:18:39 by honguyen          #+#    #+#              #
#    Updated: 2024/01/30 22:10:32 by nthoach          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT = ../libft/libft.a

SRC = 1_push_swap.c 2_sort_stack_V1.c 3_optimal_rotation.c \
		4_apply_rotation 5_basic_moves.c 6_check_utils.c \
		7_free_utils.c 8_stack_utils.c 
SRC_BONUS = 9_checker.c 

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	$(info CREATED $@)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $< ../libft/libft.a -o $@
	$(info CREATED $(NAME))
	@echo "\033[34;5mpushswap\033[0m"

$(LIBFT):
	make -C ../libft

clean:
	$(RM) $(OBJ)
	make -C ../libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re