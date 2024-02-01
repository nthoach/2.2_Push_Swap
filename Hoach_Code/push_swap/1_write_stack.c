/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_write_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:34:24 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 00:56:12 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/* This function sets the index for each node is ONE*/

void	fn_set_index(t_stack *stk_a, size_t i)
{
	while (stk_a)
	{
		stk_a->index = i;
		stk_a = stk_a->next;
	}
}

/* This function assigns index to each number from
   min (1) to max (size of stactk) */

void	fn_index_stack(t_stack *st_a)
{
	t_stack	*tmp;

	fn_set_index(st_a, 0);
	while (st_a->next)
	{
		tmp = st_a->next;
		while (tmp)
		{
			if (st_a->nbr > tmp->nbr)
				st_a->index++;				
			else
				tmp->index++;
			tmp = tmp->next;
		}
		st_a = st_a->next;		
	}
}

int	ft_atoi_ps(const char *str)
{
	int			sign;	
	long long	value;

	value = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			msg_err();
		value = value * 10 + sign * (*str - '0');
		if ((sign * value) > INT32_MAX || (sign * value) < INT32_MIN)
			msg_err();
		str++;
	}
	return (value);
}

/* write_stack function is to converter each ascii in str 
	into relevant number and write into stack a */

t_stack	*fn_writestack1(char *str)
{
	t_stack	*a;
	char	**ar_str;
	int		i;
	int		nbr;

	i = 0;
	a = NULL;
	ar_str = ft_split(str, ' ');
	while (ar_str[i])
	{
		nbr = ft_atoi_ps(ar_str[i]);
		fn_add2last(&a, fn_newnode(nbr));
		i++;
	}
	fn_freearr(ar_str);
	free(ar_str);
	return (a);
}

t_stack	*fn_writestack2(int agc, char **agv, t_stack **a)
{
	int		i;
	int		nbr;

	i = 1;
	while (i < agc)
	{
		nbr = ft_atoi_ps(agv[i]);
		fn_add2last(a, fn_newnode(nbr));
		i++;
	}
	return (*a);
}
/*
	The main program accepts two kinds of input:
	1) ./push_swap "1 5 7 9" for agc = 2, --> fn_writestack1 
	or ./push_swap 1 5 7 9 for agc > 2; ->fn_writestack2
	2) To write into stack a
*/

t_stack	*fn_writestack(int agc, char **agv)
{
	t_stack	*st_a;

	st_a = NULL;
	if (agc < 2)
		return (NULL);
	else if (agc == 2)
		st_a = fn_writestack1(agv[1]);
	else
		st_a = fn_writestack2(agc, agv, &st_a);
	return (st_a);
}
