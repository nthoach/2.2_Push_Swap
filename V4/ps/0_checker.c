/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_checker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:01:08 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/07 17:25:37 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_apply_move(t_stack **a, t_stack **b, char *mv, int *err)
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
		*err = 1;
}

void	fn_check(t_stack	**a, char *mv, int *err)
{
	t_stack	*st_b;
	int		size_a;

	size_a = fn_size(*a);
	st_b = NULL;
	while (mv)
	{
		fn_apply_move(a, &st_b, mv, err);
		free(mv);
		if (*err)
			return ;
		mv = get_next_line_err(STDIN_FILENO, err);
	}
	if (!(st_b) && fn_checksorted(*a) && size_a == fn_size(*a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}

static void	clean_gnl(int *err)
{
	if (*err)
	{
		get_next_line_err(STDIN_FILENO, err);
		msg_err();
	}
}

int	main(int agc, char **agv)
{
	t_stack	*st_a;
	char	*mv;
	int		error;

	error = 0;
	st_a = fn_writestack(agc, agv, &error);
	if (!st_a && !error)
		return (0);
	else if (!st_a && error)
		msg_err();
	if (fn_checkduplicate(st_a) || error)
	{
		fn_freestack(&st_a);
		msg_err();
	}
	mv = get_next_line_err(STDIN_FILENO, &error);
	if (!mv && fn_checksorted(st_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else if (!mv && !fn_checksorted(st_a))
		write(STDOUT_FILENO, "KO\n", 3);
	else
		fn_check(&st_a, mv, &error);
	fn_freestack(&st_a);
	clean_gnl(&error);
	return (0);
}
