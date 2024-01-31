/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:43:27 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:26 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fn_checkduplicate(t_stack *st_a)
{
	t_stack	*tmp;

	while (st_a->next)
	{
		tmp = st_a->next;
		while (tmp)
		{
			if (st_a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		st_a = st_a->next;
	}
	return (0);
}

int	fn_checksorted(t_stack *st_a)
{
	int	i;

	i = st_a->nbr;
	while (st_a->next)
	{
		st_a = st_a->next;
		if (i > st_a->nbr)
			return (0);
		i = st_a->nbr;
	}
	return (1);
}
