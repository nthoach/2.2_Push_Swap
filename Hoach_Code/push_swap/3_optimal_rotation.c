/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_optimal_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:49:06 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 09:39:33 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return number of rr + ra/rb moves needed to push nbr 
// from b to a

int	fn_rr_pa(t_stack *st_a, t_stack *st_b, int nbr)
{
	int	i;

	i = fn_find_loc_a(st_a, nbr);
	if (i < fn_find_loc(st_b, nbr))
		i = fn_find_loc(st_b, nbr);
	return (i);
}

// return the number of rrr + rra/rrab needed to push back
// nbr from a to b (a should be arranged in correct order
// after pa - descending in circle shape)

int	fn_rrr_pa(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (fn_find_loc_a(a, nbr))
		i = fn_size(a) - fn_find_loc_a(a, nbr);
	if ((i < (fn_size(b) - fn_find_loc(b, nbr)))
		&& fn_find_loc(b, nbr))
		i = fn_size(b) - fn_find_loc(b, nbr);
	return (i);
}

// return the number of moves of ra + rrb

int	fn_rarrb_pa(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (fn_find_loc(b, nbr))
		i = fn_size(b) - fn_find_loc(b, nbr);
	i += fn_find_loc_a(a, nbr);
	return (i);
}

// return the number of moves for rra+rb

int	fn_rrarb_pa(t_stack *a, t_stack *b, int nbr)
{
	int	i;

	i = 0;
	if (fn_find_loc_a(a, nbr))
		i = fn_size(a) - fn_find_loc_a(a, nbr);
	i += fn_find_loc(b, nbr);
	return (i);
}
// return the minimum moves needed to push an 
// numberfrom b to a, the selected number is
// also the cheapest one on moves

int	fn_best_rotate(t_stack *st_a, t_stack *st_b)
{
	int		i;
	t_stack	*tmp;

	tmp = st_b;
	i = fn_rr_pa(st_a, st_b, st_b->nbr);
	while (tmp)
	{
		if (i > fn_rr_pa(st_a, st_b, tmp->nbr))
			i = fn_rr_pa(st_a, st_b, tmp->nbr);
		if (i > fn_rrr_pa(st_a, st_b, tmp->nbr))
			i = fn_rrr_pa(st_a, st_b, tmp->nbr);
		if (i > fn_rarrb_pa(st_a, st_b, tmp->nbr))
			i = fn_rarrb_pa(st_a, st_b, tmp->nbr);
		if (i > fn_rrarb_pa(st_a, st_b, tmp->nbr))
			i = fn_rrarb_pa(st_a, st_b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
