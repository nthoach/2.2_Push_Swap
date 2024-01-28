/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:44:05 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 09:37:25 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Move to the last node of the stack */
t_stack *stack_last(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

/* to create new node for new number */
t_stack *stack_new_node(int  nbr)
{   
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        msg_err();
    new->nbr = nbr;
    new->next = NULL;
    return (new);
}

/* add a stack node to the last */
void    stack_add_back(t_stack **a, t_stack *new_node)
{
    if (!a)
        return ;
    else if (!*a)
        *a = new_node;
    else
        (stack_last(*a))->next = new_node;
}

/* size of stack */
int	size_stack(t_stack *stk)
{
	size_t	len;

	len = 0;
	while (stk)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}
int index_min(t_stack *a, int min)
{
    int ind;

    ind = 1;
    while (a)
    {
        if (a->index == min)
            return (ind);
        ind++;
        a = a->next;
    }
    return (ind);
}