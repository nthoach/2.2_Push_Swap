/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_free_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:43:49 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/31 21:21:57 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print an error message

void	msg_err(void)
{
	write (STDERR_FILENO, "Error\n", 6);
	exit(1);
}

// This function frees the stack.

void	fn_freestack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->nbr = 0;
		(*a)->index = 0;
		free(*a);
		*a = tmp;
	}
}

// This function free the string array

void	fn_freearr(char **arr_str)
{
	char	*str;

	if (!arr_str)
		return ;
	while (*arr_str)
	{
		str = *arr_str;
		arr_str++;
		free(str);
	}
}
