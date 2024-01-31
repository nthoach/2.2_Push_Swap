/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:10:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 19:53:39 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotates both a and b with the procedure: rr + ra/rb + rb/ra

int	fn_apply_rr(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && fn_find_loc_b(*b, c) > 0)
			fn_rr(a, b, 0);
		while ((*a)->nbr != c)
			fn_ra(a, 0);
		while (fn_find_loc_b(*b, c) > 0)
			fn_rb(b, 0);
		fn_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && fn_find_loc_a(*a, c) > 0)
			fn_rr(a, b, 0);
		while ((*b)->nbr != c)
			fn_rb(b, 0);
		while (fn_find_loc_a(*a, c) > 0)
			fn_ra(a, 0);
		fn_pa(a, b, 0);
	}
	return (-1);
}

// reverse rotate both a and b

int	fn_apply_rrr(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && fn_find_loc_b(*b, c) > 0)
			fn_rrr(a, b, 0);
		while ((*a)->nbr != c)
			fn_rra(a, 0);
		while (fn_find_loc_b(*b, c) > 0)
			fn_rrb(b, 0);
		fn_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && fn_find_loc_a(*a, c) > 0)
			fn_rrr(a, b, 0);
		while ((*b)->nbr != c)
			fn_rrb(b, 0);
		while (fn_find_loc_a(*a, c) > 0)
			fn_rra(a, 0);
		fn_pa(a, b, 0);
	}
	return (-1);
}

// rotate separate

int	fn_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			fn_rra(a, 0);
		while (fn_find_loc_b(*b, c) > 0)
			fn_rb(b, 0);
		fn_pb(a, b, 0);
	}
	else
	{
		while (fn_find_loc_a(*a, c) > 0)
			fn_rra(a, 0);
		while ((*b)->nbr != c)
			fn_rb(b, 0);
		fn_pa(a, b, 0);
	}
	return (-1);
}

// rotate separate in different direction

int	fn_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			fn_ra(a, 0);
		while (fn_find_loc_b(*b, c) > 0)
			fn_rrb(b, 0);
		fn_pb(a, b, 0);
	}
	else
	{
		while (fn_find_loc_a(*a, c) > 0)
			fn_ra(a, 0);
		while ((*b)->nbr != c)
			fn_rrb(b, 0);
		fn_pa(a, b, 0);
	}
	return (-1);
}
