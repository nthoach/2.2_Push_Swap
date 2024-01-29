/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort_stack_V1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:50 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/29 18:38:00 by honguyen         ###   ########.fr       */
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

t_stack	**ft_sort_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = ft_rotate_type_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'b');
			else if (i == ft_case_rarrb_a(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_case_rrarrb_a(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_case_rrarb_a(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

void  ft_raxn(t_stack **a, int min)
{
   while ((*a)->index != min)
   {   
		ft_ra(a, 0);
      if (check_inv_cons(*a))
         ft_sa(a, 0);
   }
}
void  ft_rraxn(t_stack **a, int min)
{
   
	while ((*a)->index != min)
   {
		ft_rra(a, 0);
	   if (check_inv_cons(*a))
         ft_sa(a, 0);
	}
	
}

void    sort_stack(t_stack **a)
{
    t_stack *st_b;
	int		i;

    st_b = NULL;
    if (size_stack(*a) == 2)
        ft_sa(a, 0);   
    else
    {
        while (size_stack(*a) > 3)
            ft_pb(a, &st_b, 0);
        ft_sort_three(a);
        a = ft_sort_a(a, &st_b);
		i = ft_find_index(*a, ft_min(*a));
		if (i < size_stack(*a) - i)
		{
			while ((*a)->nbr != ft_min(*a))
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->nbr != ft_min(*a))
				ft_rra(a, 0);
		}	
	//	return ;
    //    if (index_min(*a, 1) <= size_stack(*a) / 2 + 1)
	//	    ft_raxn(a, 1);
    //    else
    //      ft_rraxn(a, 1);
    }
}
