/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:41:13 by marvin            #+#    #+#             */
/*   Updated: 2024/01/25 13:41:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
// Print an error message
void	msg_err(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

// This function frees the stack.
void	free_stack(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return ;
	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->nbr = 0;
		free(*stack_a);
		*stack_a = tmp;
	}
}

// This function free the string array
void	free_arr(char **ar_str)
{
	char	*n1;

	if (!ar_str)
		return ;
	while (*ar_str)
	{
		n1 = *ar_str;
		ar_str++;
		free(n1);
	}
	*ar_str = NULL;
}