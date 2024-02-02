/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:01:08 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/02 09:37:05 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_apply_move(t_stack **a, t_stack **b, char	*mv)
{
	if (mv[0] == 's' && mv[1] == 'a' && mv[2] == '\n')
		fn_sa(a, 1);
	else if (mv[0] == 's' && mv[1] == 'b' && mv[2] == '\n')
		fn_sb(b, 1);
	else if (mv[0] == 's' && mv[1] == 's' && mv[2] == '\n')
		fn_ss(a, b, 1);
	else if (mv[0] == 'p' && mv[1] == 'a' && mv[2] == '\n')
		fn_pa(a, b, 1);
	else if (mv[0] == 'p' && mv[1] == 'b' && mv[2] == '\n')
		fn_pb(a, b, 1);
	else if (mv[0] == 'r' && mv[1] == 'a' && mv[2] == '\n')
		fn_ra(a, 1);
	else if (mv[0] == 'r' && mv[1] == 'b' && mv[2] == '\n')
		fn_rb(b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == '\n')
		fn_rr(a, b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'a' && mv[3] == '\n')
		fn_rra(a, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'b' && mv[3] == '\n')
		fn_rrb(b, 1);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'r' && mv[3] == '\n')
		fn_rrr(a, b, 1);
	else
		msg_err();
}

void	fn_check(t_stack	**a, char *mv)
{
	t_stack	*st_b;
	int		size_a;
	char	*mv_fr;

	size_a = fn_size(*a);
	st_b = NULL;
	while (mv && *mv != '\n')
	{
		mv_fr = mv;
		fn_apply_move(a, &st_b, mv);
		mv = get_next_line(STDIN_FILENO);
		free(mv_fr);
	}
	if (!(st_b) && fn_checksorted(*a) && size_a == fn_size(*a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

int	main(int agc, char **agv)
{
	t_stack	*st_a;
	char	*mv;

	st_a = fn_writestack(agc, agv);
	if (!st_a || fn_checkduplicate(st_a))
	{
		fn_freestack(&st_a);
		msg_err();
	}
	mv = get_next_line(STDIN_FILENO);
	if (!mv && fn_checksorted(st_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else if (!mv && !fn_checksorted(st_a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		fn_check(&st_a, mv);
	fn_freestack(&st_a);
	return (0);
}
