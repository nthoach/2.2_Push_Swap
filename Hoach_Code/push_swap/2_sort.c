/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/01 23:44:49 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/* Optimal sorting for stack with 3 numbers*/

void	fn_sort_three(t_stack **a)
{
	bool	cmp1;
	bool	cmp2;
	bool	cmp3;

	cmp1 = (*a)->nbr < (*a)->next->nbr;
	cmp2 = (*a)->next->nbr < (*a)->next->next->nbr;
	cmp3 = (*a)->next->next->nbr < (*a)->nbr;
	if (cmp1 && !cmp2 && !cmp3)
	{
		fn_sa(a, 0);
		fn_ra(a, 0);
	}
	else if (!cmp1 && !cmp2 && cmp3)
	{
		fn_ra(a, 0);
		fn_sa(a, 0);
	}
	else if (!cmp1 && cmp2 && !cmp3)
		fn_sa(a, 0);
	else if (cmp1 && !cmp2 && cmp3)
		fn_rra(a, 0);
	else if (!cmp1 && cmp2 && cmp3)
		fn_ra(a, 0);
}

/* Sorting a by selecting best node from b to push back to a */
/* best_rotate_ba = best rotation to push a from b */

t_stack	**fn_best_pusha(t_stack **a, t_stack **b)
{
	long	i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = fn_best_rotate(*a, *b);
		while (i >= 0)
		{
			if (i == fn_rr_pa(*a, *b, tmp->nbr))
				i = fn_apply_rr(a, b, tmp->nbr);
			else if (i == fn_rrr_pa(*a, *b, tmp->nbr))
				i = fn_apply_rrr(a, b, tmp->nbr);				
			else if (i == fn_rarrb_pa(*a, *b, tmp->nbr))
				i = fn_apply_rarrb(a, b, tmp->nbr);
			else if (i == fn_rrarb_pa(*a, *b, tmp->nbr))
				i = fn_apply_rrarb(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
	return (a);
}
// && ((*b)->next && (*b)->index == (*b)->next->index + 1)

void	fn_sort(t_stack **a)
{
	t_stack	*st_b;
	int		i;

	st_b = NULL;
	if (fn_size(*a) == 2)
		fn_sa(a, 0);
	else
	{
		while (fn_size(*a) > 3 && !fn_checksorted(*a))
		{
			fn_pb(a, &st_b, 0);
			if ((*a)->index == (*a)->next->index - 1)
				fn_ss(a, &st_b, 0);
		}
		if (!fn_checksorted(*a))
			fn_sort_three(a);
		if (st_b)
			fn_best_pusha(a, &st_b);
		i = fn_find_loc(*a, fn_findmin(*a));
		if (i < fn_size(*a) - i)
		{
			while ((*a)->index != 0)
				fn_ra(a, 0);
		}
		else
		{
			while ((*a)->index != 0)
				fn_rra(a, 0);
		}
	}
}
