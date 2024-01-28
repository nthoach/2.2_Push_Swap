/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_check_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:43:27 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 19:08:43 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   check_invalid(t_stack *a)
{
	t_stack *tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int    check_sorted(t_stack *st_a)
{
    	int	i;

	i = st_a->nbr;
	while (st_a)
	{
		if (i > st_a->nbr)
			return (0);
		i = st_a->nbr;
		st_a = st_a->next;
	}
	return (1);
}
int check_inv_cons(t_stack *st)
{
    if (st->index == (st->next->index) + 1)
		return (1);
	return (0);
}