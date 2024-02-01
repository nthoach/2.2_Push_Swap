/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:48:56 by nthoach           #+#    #+#             */
/*   Updated: 2024/01/30 22:48:14 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
	1) write input to stack a (*st_a)
	2) check stack_a is valid/duplicate/sorted
	3) do the sorting
*/

int	main(int agc, char **agv)
{
	t_stack	*st_a;

	st_a = write2stack(agc, agv);
	//indexing_stack(st_a);
	if (!st_a || check_invalid(st_a))
	{
		free_stack(&st_a);
		msg_err();
	}
	else if (!check_sorted(st_a))	
		sort_stack(&st_a);
	free_stack(&st_a);
	return (0);
}