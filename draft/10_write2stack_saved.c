/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_write2stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:47:44 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/01 23:01:25 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	fn_set_index(t_stack *stk_a, size_t i)
{
	while (stk_a)
	{
		stk_a->index = i;
		stk_a = stk_a->next;
	}
}

void fn_index_stack(t_stack *st_a)
{
	t_stack	*tmp;
	
	fn_set_index(st_a, 1);
	while (st_a->next)
	{
		tmp = st_a->next;
		while (tmp)
		{
			if (st_a->nbr > tmp->nbr)
				(st_a->index)++;				
			else
				(tmp->index)++;
			tmp = tmp->next;
		}
		st_a = st_a->next;		
	}
}

/*
write_stack function is to converter each ascii in str into relevant number
and write into stack a
*/

t_stack	*write_stack(char *str)
{
	t_stack	*a;
	char		**ar_str;
	int		i;
	int		nbr;

	i = 0;
	a = NULL;
	ar_str = ft_split(str, ' ');
	while (ar_str[i])
	{
		nbr = ft_atoi(ar_str[i]);
		stack_add_back(&a, stack_new_node(nbr));
		i++;
	}
	free_arr(ar_str);
	free(ar_str);
	return (a);
}

/*
	The main program accepts two kinds of input:
	1) ./push_swap "1 5 7 9" for agc = 2, 
	or ./push_swap 1 5 7 9 for agc > 2;
	2) To write into stack a
*/

t_stack	*write2stack(int agc, char **agv)
{
	int		i;
	int		nbr;
	t_stack	*a;
	
	a = NULL;
	if (agc < 2)
		msg_err();
	else if (agc > 2)
	{
		i = 1;
		while (i < agc)
		{
			nbr = ft_atoi(agv[i]);
			stack_add_back(&a, stack_new_node(nbr));
			i++;
		}
	}
	else
		a = write_stack(agv[1]);
	return (a);
}