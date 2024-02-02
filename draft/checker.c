/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:01:08 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/02 09:40:38 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_move(t_stack **a, t_stack **b, char	*mv)
{
	if (mv[0] == 's' && mv[1] == 'a' && mv[2] == '\n')
		ft_sa(a, 1);
	else if (mv[0] == 's' && mv[1] == 'b' && mv[2] == '\n')
		ft_sb(b, 1);
	else if (mv[0] == 's' && mv[1] == 's' && mv[2] == '\n')
		ft_ss(a, b, 1);
	else if (mv[0] == 'p' && mv[1] == 'a' && mv[2] == '\n')
		ft_pa(a, b, 1);
	else if (mv[0] == 'p' && mv[1] == 'b' && mv[2] == '\n')
		ft_pb(a, b, 1);
	else if (mv[0] == 'r' && mv[1] == 'a' && mv[2] == '\n')
		ft_ra(a, 1);
	else if (mv[0] == 'r' && mv[1] == 'b' && mv[2] == '\n')
		ft_rb(b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == '\n')
		ft_rr(a, b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'a' && mv[3] == '\n')
		ft_rra(a, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'b' && mv[3] == '\n')
		ft_rrb(b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'r' && mv[3] == '\n')
		ft_rrr(a, b, 1);
	else
		msg_err();
}

void	check_pushswap(t_stack	**a, char *mv)
{
	t_stack	**b;
	int		size_a;
	char	*mv_fr;

	size_a = size_stack(*a);
	b = NULL;
	while (mv && *mv != '\n')
	{
		mv_fr = mv;
		apply_move(a, b, mv);
		mv = get_next_line(STDIN_FILENO);
		free(mv_fr);
	}
	free(mv);
	if (!(*b) && check_sorted(*a) && size_a == size_stack(*a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stack(b);
}

void	msg_err_checker(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int agc, char **agv)
{
	t_stack	*st_a;
	char		*mv;
	
	st_a = write2stack(agc, agv);
	indexing_stack(st_a);
	if (!st_a || check_invalid(st_a))
	{
		free_stack(&st_a);
		msg_err_checker();
	}
	mv = get_next_line(STDIN_FILENO);
	if (!mv && check_sorted(st_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else if (!mv && !check_sorted(st_a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		check_pushswap(&st_a, mv);
	free(mv);
	free_stack(&st_a);
	return (0);
}