/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_optimal_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:49:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 21:26:18 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates the required amount of rotation.
// Calculations are done for ra+rb case.

int	fn_rr_pa(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = fn_find_loc_a(a, c);
	if (i < fn_find_loc(b, c))
		i = fn_find_loc(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rrb case.
int	fn_rrr_pa(t_stack *a, t_stack *b, int c)
{
	size_t	i;

	i = 0;
	if (fn_find_loc_a(a, c))
		i = fn_size(a) - fn_find_loc_a(a, c);
	if ((i < (fn_size(b) - fn_find_loc(b, c))) && fn_find_loc(b, c))
		i = fn_size(b) - fn_find_loc(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	fn_rarrb_pa(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (fn_find_loc(b, c))
		i = fn_size(b) - fn_find_loc(b, c);
	i = fn_find_loc_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	fn_rrarb_pa(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (fn_find_loc_a(a, c))
		i = fn_size(a) - fn_find_loc_a(a, c);
	i = fn_find_loc(b, c) + i;
	return (i);
}

int	fn_best_rotate(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = fn_rrr_pa(a, b, b->nbr);
	while (tmp)
	{
		if (i > fn_rr_pa(a, b, tmp->nbr))
			i = fn_rr_pa(a, b, tmp->nbr);
		if (i > fn_rrr_pa(a, b, tmp->nbr))
			i = fn_rrr_pa(a, b, tmp->nbr);
		if (i > fn_rarrb_pa(a, b, tmp->nbr))
			i = fn_rarrb_pa(a, b, tmp->nbr);
		if (i > fn_rrarb_pa(a, b, tmp->nbr))
			i = fn_rrarb_pa(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
