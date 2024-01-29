/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_basic_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:42:23 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/29 18:27:09 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	stack_last(*a)->next = *a;
	*a = (*a)->next;
	tmp->next = 0;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp1 = *a;
	while(tmp->next->next)
		tmp = tmp->next;
	*a = tmp->next;
	tmp->next = NULL;
	(*a)->next = tmp1;
	// while ((*a)->next)
	// {
	// 	*a = (*a)->next;
	// 	i++;
	// }
	// (*a)->next = tmp;
	// while (i > 1)
	// {
	// 	tmp = tmp->next;
	// 	i--;
	// }
	// tmp->next = 0;
	if (j == 0)
		write(1, "rra\n", 4);
}

// rrb (reverse rotate b) : shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	ft_ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "ss\n", 3);
}

// rr : ra and rb at the same time
void	ft_rr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = stack_last(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = stack_last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

// Second part of the rrr function
void	ft_rrr_sub(t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrr\n", 4);
}

// rrr : rra and rrb at the same time.
void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_rrr_sub(b, j);
}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = stack_last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

// sb (swap b) : swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
void	ft_sb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}
