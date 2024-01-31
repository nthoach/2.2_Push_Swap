# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 13:18:39 by honguyen          #+#    #+#              #
#    Updated: 2024/01/31 20:53:25 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFTA = ../libft/libft.a

SRC_PS = 0_push_swap.c 
SRC_BONUS = 0_checker.c 
SRC_FN = 1_write_stack.c  2_sort.c 3_optimal_rotation.c 3_apply_rotation.c \
		4_check_utils.c 4_free_utils.c 5_basic_moves_1.c 5_basic_moves_2.c \
		5_basic_moves_3.c 5_stack_utils_1.c 5_stack_utils_2.c 

OBJ_PS = ${SRC_PS:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
OBJ_FN = ${SRC_FN:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ_PS) $(OBJ_FN)
	make -C ../libft
	$(CC) $(CFLAGS) $(OBJ_PS) $(OBJ_FN) $(LIBFTA) -o $@

${BONUS}: ${OBJ_FN} ${OBJ_BONUS} 
	make -C ../libft
	${CC} ${FLAGS} ${OBJ_BONUS} ${OBJ_FN} $(LIBFTA) -o $@

all: $(NAME)

bonus: $(BONUS)

clean:
	$(RM) $(OBJ_PS) $(OBJ_FN) $(OBJ_BONUS)
	make -C ../libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS) $(LIBFTA)

re: fclean all bonus

.PHONY: all clean fclean re