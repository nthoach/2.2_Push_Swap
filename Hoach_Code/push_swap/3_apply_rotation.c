/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_apply_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:53:28 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 09:53:31 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotates both a and b with the procedure: rr + ra/rb + rb/ra

int	fn_apply_rr(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->nbr != nbr && fn_find_loc_a(*a, nbr) > 0)
		fn_rr(a, b, 0);
	while ((*b)->nbr != nbr)
		fn_rb(b, 0);
	while (fn_find_loc_a(*a, nbr) > 0)
		fn_ra(a, 0);
	fn_pa(a, b, 0);
	return (-1);
}

// reverse rotate both a and b

int	fn_apply_rrr(t_stack **a, t_stack **b, int nbr)
{
	while ((*b)->nbr != nbr && fn_find_loc_a(*a, nbr) > 0)
		fn_rrr(a, b, 0);
	while ((*b)->nbr != nbr)
		fn_rrb(b, 0);
	while (fn_find_loc_a(*a, nbr) > 0)
		fn_rra(a, 0);
	fn_pa(a, b, 0);
	return (-1);
}

// rotate separate

int	fn_apply_rrarb(t_stack **a, t_stack **b, int nbr)
{
	while (fn_find_loc_a(*a, nbr) > 0)
		fn_rra(a, 0);
	while ((*b)->nbr != nbr)
		fn_rb(b, 0);
	fn_pa(a, b, 0);
	return (-1);
}

// rotate separate in different direction

int	fn_apply_rarrb(t_stack **a, t_stack **b, int nbr)
{
	while (fn_find_loc_a(*a, nbr) > 0)
		fn_ra(a, 0);
	while ((*b)->nbr != nbr)
		fn_rrb(b, 0);
	fn_pa(a, b, 0);
	return (-1);
}
