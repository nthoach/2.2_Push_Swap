/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:44:05 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/29 18:18:38 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function finds and returns the smallest number
// in the given stack.
int	ft_min(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

// This function finds and returns the biggest number
// in the given stack.
int	ft_max(t_stack *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}
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

// This function checks the index of a number
// 	 in the stack.
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < (stack_last(stack_b))->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_a.
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > stack_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
