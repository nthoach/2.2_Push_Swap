/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:43:49 by honguyen          #+#    #+#             */
/*   Updated: 2024/01/29 19:02:21 by honguyen         ###   ########.fr       */
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
void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->nbr = 0;
		free(*a);
		*a = tmp;
	}
}

// This function free the string array
void	free_arr(char **arr_str)
{
	char	*n1;

	if (!arr_str)
		return ;
	while (*arr_str)
	{
		n1 = *arr_str;
		arr_str++;
		free(n1);
	}
	*arr_str = NULL;
}