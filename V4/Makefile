# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 13:18:39 by honguyen          #+#    #+#              #
#    Updated: 2024/02/02 16:28:12 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f
LIBFTA = ./libft/libft.a
HEADER = ps/push_swap.h

SRC_PS = ps/0_push_swap.c 
SRC_BONUS = ps/0_checker.c 
SRC_FN = ps/1_write_stack.c ps/1_set_index.c  ps/2_sort.c \
		ps/3_optimal_rotation.c ps/3_apply_rotation.c ps/4_check_utils.c \
		ps/4_free_utils.c ps/5_basic_moves_1.c ps/5_basic_moves_2.c \
		ps/5_basic_moves_3.c ps/5_stack_utils_1.c ps/5_stack_utils_2.c

OBJ_PS = ${SRC_PS:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
OBJ_FN = ${SRC_FN:.c=.o}

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_PS) $(OBJ_FN)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_PS) $(OBJ_FN) $(LIBFTA) -o $@

${BONUS}: ${OBJ_FN} ${OBJ_BONUS}
	make -C ./libft
	${CC} ${FLAGS} ${OBJ_BONUS} ${OBJ_FN} $(LIBFTA) -o $@

all: $(NAME)

bonus: $(BONUS)

clean:
	$(RM) $(OBJ_PS) $(OBJ_FN) $(OBJ_BONUS)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS) $(LIBFTA)

re: fclean all bonus

.PHONY: all clean fclean re