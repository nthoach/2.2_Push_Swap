/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:48:56 by nthoach           #+#    #+#             */
/*   Updated: 2024/01/31 21:03:40 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	fn_index_stack(st_a);
	if (!st_a || fn_checkduplicate(st_a))
	{
		fn_freestack(&st_a);
		msg_err();
	}
	else if (!fn_checksorted(st_a))
		fn_sort(&st_a);
	fn_freestack(&st_a);
	return (0);
}
