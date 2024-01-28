/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:44:05 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 18:25:04 by nthoach          ###   ########.fr       */
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
	int	len;
	t_stack	*tmp;

	len = 0;
	tmp = stk;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
int index_min(t_stack *st_a, int min)
{
    int ind;
	 t_stack	*tmp;

    ind = 1;
	 tmp = st_a;
    while (tmp)
    {
        if (tmp->index == min)
            return (ind);
        ind++;
        tmp = tmp->next;
    }
    return (ind);
}
void	stack_printf(t_stack *st_a)
{
	while (st_a)
	{
		ft_printf("%d:", st_a->index);
		st_a = st_a->next;
	}
	ft_printf("\n");
}