/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:33:31 by marvin            #+#    #+#             */
/*   Updated: 2024/01/28 09:36:58 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void		set_index(t_stack *stk_a, int i);
void		indexing_stack(t_stack *stk_a);
t_stack		*write_stack(char *str);
t_stack		*write2stack(int agc, char **agv);
void		ft_sort_three(t_stack **a);
void    	sort_stack(t_stack **a);
void  		ft_raxn(t_stack **a);
void  		ft_rraxn(t_stack **a);
void		ft_min2top(t_stack **a, int min);
void		ft_sa(t_stack **a, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **a, t_stack **b, int j);
void		ft_ra(t_stack **a, int j);
void		ft_rra(t_stack **a, int j);
int  		check_invalid(t_stack *a);
int			check_sorted(t_stack *a);
int			check_inv_cons(t_stack **a);
void		msg_err(void);
void		free_stack(t_stack **stack_a);
void		free_arr(char **ar_str);
t_stack		*stack_last(t_stack *lst);
t_stack		*stack_new_node(int  nbr);
void		stack_add_back(t_stack **a, t_stack *new_node);
int			size_stack(t_stack *stk);
int			index_min(t_stack *a, int min);

#endif