/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_write_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:34:24 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/02 15:14:16 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char	**arr_str;
	int		j;

	i = 1;
	while (i < agc)
	{
		arr_str = ft_split(agv[i], ' ');
		j = 0;
		while (arr_str[j])
		{
			nbr = ft_atoi_ps(arr_str[j]);
			fn_add2last(a, fn_newnode(nbr));
			j++;
		}
		fn_freearr(arr_str);
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
