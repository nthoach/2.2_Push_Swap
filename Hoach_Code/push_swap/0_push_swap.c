/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:48:56 by nthoach           #+#    #+#             */
/*   Updated: 2024/02/02 01:02:43 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
	1) read input and write to stack A
	2) check validity: duplicate/NULL
	3) check if not sorted -> sorted/ or do nothing
*/

int	main(int agc, char **agv)
{
	t_stack	*st_a;

	st_a = fn_writestack(agc, agv);
	if (!st_a)
		return (0);
	if (fn_checkduplicate(st_a))
	{
		fn_freestack(&st_a);
		msg_err();
		return (-1);
	}
	else if (!fn_checksorted(st_a))
	{
		fn_index_stack(st_a);
		fn_sort(&st_a);
	}

	fn_freestack(&st_a);
	return (0);
}