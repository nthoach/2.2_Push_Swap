/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_basic_moves_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:36:02 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 20:42:59 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fn_ra(t_stack **a, int j)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	fn_move2last(*a)->next = *a;
	*a = (*a)->next;
	tmp->next = 0;
	if (j == 0)
		write(1, "ra\n", 3);
}

void	fn_rb(t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = fn_move2last(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void	fn_rr(t_stack **a, t_stack **b, int j)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	fn_ra(a, 1);
	fn_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	fn_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp1 = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	*a = tmp->next;
	tmp->next = NULL;
	(*a)->next = tmp1;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	fn_rrb(t_stack **b, int j)
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
