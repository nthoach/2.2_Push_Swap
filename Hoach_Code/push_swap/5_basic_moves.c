/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_basic_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:42:23 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 19:05:40 by nthoach          ###   ########.fr       */
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
