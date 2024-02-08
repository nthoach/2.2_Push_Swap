/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_write_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:34:24 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/07 17:14:48 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(const char *str, int *err)
{
	int			sign;	
	long long	value;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			value = value * 10 + sign * (*str - '0');
		if (value > INT32_MAX || value < INT32_MIN
			|| (*str) < '0' || (*str) > '9')
			*err = 1;
		if (*err)
			break ;
		str++;
	}
	return (value);
}

/* write_stack function is to converter each ascii in str 
	into relevant number and write into stack a */

t_stack	*fn_writestack1(char *str, int *err)
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
		nbr = ft_atoi_ps(ar_str[i], err);
		if (*err)
			break ;
		fn_add2last(&a, fn_newnode(nbr));
		i++;
	}
	fn_freearr(ar_str);
	free(ar_str);
	return (a);
}

t_stack	*fn_writestack2(int agc, char **agv, t_stack **a, int *err)
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
			nbr = ft_atoi_ps(arr_str[j], err);
			if (*err)
				break ;
			fn_add2last(a, fn_newnode(nbr));
			j++;
		}
		fn_freearr(arr_str);
		free(arr_str);
		if (*err)
			break ;
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

t_stack	*fn_writestack(int agc, char **agv, int *err)
{
	t_stack	*st_a;

	st_a = NULL;
	if (agc < 2)
		return (NULL);
	else if (agc == 2)
		st_a = fn_writestack1(agv[1], err);
	else
		st_a = fn_writestack2(agc, agv, &st_a, err);
	return (st_a);
}
