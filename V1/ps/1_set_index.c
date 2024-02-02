/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_set_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:38:20 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 09:45:07 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function sets the index for each node to i */

void	fn_set_index(t_stack *stk_a, size_t i)
{
	while (stk_a)
	{
		stk_a->index = i;
		stk_a = stk_a->next;
	}
}

/* This function assigns index to each number from
   min (1) to max (size of stactk) */

void	fn_index_stack(t_stack *st_a)
{
	t_stack	*tmp;

	fn_set_index(st_a, 0);
	while (st_a->next)
	{
		tmp = st_a->next;
		while (tmp)
		{
			if (st_a->nbr > tmp->nbr)
				st_a->index = st_a->index + 1;
			else
				tmp->index++;
			tmp = tmp->next;
		}
		st_a = st_a->next;
	}
}
