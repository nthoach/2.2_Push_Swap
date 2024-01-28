/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 10:42:15 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	bool cmp1;
    bool cmp2;
    bool cmp3;
    
    cmp1 = (*a)->nbr < (*a)->next->nbr;
    cmp2 = (*a)->next->nbr < (*a)->next->next->nbr;
    cmp3 = (*a)->next->next->nbr < (*a)->nbr;
    if (cmp1 && !cmp2 && !cmp3)
	{
		ft_sa(a, 0);
		ft_ra(a, 0);
	}
	else if (!cmp1 && cmp2 && !cmp3)
		ft_sa(a, 0);
	else if (cmp1 && !cmp2 && cmp3)
		ft_rra(a, 0);
    else if (!cmp1 && cmp2 && cmp3)
		ft_ra(a, 0);
    else if (!cmp1 && !cmp2 && cmp3)
	{
		ft_ra(a, 0);
		ft_sa(a, 0);
	} 
}
  

void    sort_stack(t_stack **a)
{
    t_stack *stk_b;
    int     min;

    min = 1;
    stk_b = 0;
    if (size_stack(*a) == 2)
        ft_sa(a, 0);   
    else
    {
        while (size_stack(*a) > 3)
        {
				ft_min2top(a, min);
				if (check_sorted(*a))
					break ;
            ft_pb(a, &stk_b, 0);
            if (check_sorted(*a))
                break ;
				ft_printf("min=%d:\n", min);//
				ft_printf("stack_b=%d:\n", stk_b->nbr);//
				min++;
        }
        if (size_stack(*a) == 3)
            ft_sort_three(a);
        while (stk_b)
            ft_pa(a, &stk_b, 0);
    }
}
