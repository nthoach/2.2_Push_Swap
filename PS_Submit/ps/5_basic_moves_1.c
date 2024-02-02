/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_basic_moves_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:42:23 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 20:42:56 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_sa(t_stack **a, int j)
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

void	fn_sb(t_stack **b, int j)
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

void	fn_ss(t_stack **a, t_stack **b, int j)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	fn_sa(a, 1);
	fn_sb(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}

void	fn_pa(t_stack **a, t_stack **b, int j)
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

void	fn_pb(t_stack **a, t_stack **b, int j)
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
