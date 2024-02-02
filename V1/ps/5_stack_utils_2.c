/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_stack_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:21 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 09:55:23 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* size of stack */

int	fn_size(t_stack *st_a)
{
	int		len;

	len = 0;
	while (st_a)
	{
		st_a = st_a->next;
		len++;
	}
	return (len);
}

/* find location of an index in the stack*/

int	fn_findlocation(t_stack *st_a, int idx)
{
	int		loc;

	loc = 0;
	while (st_a)
	{
		if (st_a->index == idx)
			return (loc);
		st_a = st_a->next;
		loc++;
	}
	return (-1);
}

/* find the location of number nbr in the stack */

int	fn_find_loc(t_stack *st_a, int nbr)
{
	int	i;

	i = 0;
	while (st_a->nbr != nbr)
	{
		i++;
		st_a = st_a->next;
	}
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.

int	fn_find_loc_b(t_stack *st_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > st_b->nbr && nbr_push < (fn_move2last(st_b))->nbr)
		i = 0;
	else if (nbr_push > fn_findmax(st_b) || nbr_push < fn_findmin(st_b))
		i = fn_find_loc(st_b, fn_findmax(st_b));
	else
	{
		tmp = st_b->next;
		while (st_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			st_b = st_b->next;
			tmp = st_b->next;
			i++;
		}
	}
	return (i);
}

// This caculates the number of ra moves to push nbr_push from b
// the result will be a sorted a but in circular arrangment

int	fn_find_loc_a(t_stack *st_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < st_a->nbr && nbr_push > (fn_move2last(st_a))->nbr)
		i = 0;
	else if (nbr_push > fn_findmax(st_a) || nbr_push < fn_findmin(st_a))
		i = fn_find_loc(st_a, fn_findmin(st_a));
	else
	{
		tmp = st_a->next;
		while (st_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			st_a = st_a->next;
			tmp = st_a->next;
			i++;
		}
	}
	return (i);
}
