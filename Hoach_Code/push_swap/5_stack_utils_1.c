/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_stack_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:01 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 09:55:03 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the minimum number in the stack and return its index */

int	fn_findmin(t_stack *st_a)
{
	int		i;

	i = st_a->nbr;
	st_a = st_a->next;
	while (st_a)
	{
		if (st_a->nbr < i)
			i = st_a->nbr;
		st_a = st_a->next;
	}
	return (i);
}

/* find the maximum number in the stack and return its index */

int	fn_findmax(t_stack *st_a)
{
	int		i;

	i = st_a->nbr;
	while (st_a)
	{
		if (st_a->nbr > i)
			i = st_a->nbr;
		st_a = st_a->next;
	}
	return (i);
}

/* Move to the last node of the stack */

t_stack	*fn_move2last(t_stack *st_a)
{
	if (!st_a)
		return (NULL);
	while (st_a->next)
		st_a = st_a->next;
	return (st_a);
}

/* make new node */

t_stack	*fn_newnode(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		msg_err();
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

/* add a node to the last */

void	fn_add2last(t_stack **a, t_stack *new_node)
{
	if (!a)
		return ;
	else if (!*a)
		*a = new_node;
	else
		(fn_move2last(*a))->next = new_node;
}
