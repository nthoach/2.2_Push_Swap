/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_min2top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:43:23 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/28 10:26:16 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function do
1- Indentify the minimum value in stack a and its distance from it to
the top, from the position, it will decide to optimal move between
rra and ra;
2- Optimal move the mimium to the top of stack a 
   by selecting the optimal move between: rra x n or ra x m
*/

void  ft_raxn(t_stack **a)
{
   while ((*a)->index != 1)
   {   
      ft_ra(a, 0);
      if (check_inv_cons(a))
         ft_sa(a, 0);
   }
}

void  ft_rraxn(t_stack **a)
{
   while ((*a)->index != 1)
   {
      ft_rra(a, 0);
      if (check_inv_cons(a))
         ft_sa(a, 0);
    }
}

void    ft_min2top(t_stack **a, int min)
{
	if (check_inv_cons(a))
		ft_sa(a, 0);
	if (index_min(*a, min) <= size_stack(*a) / 2 + 1)
		ft_raxn(a);
   else
      ft_rraxn(a);
}