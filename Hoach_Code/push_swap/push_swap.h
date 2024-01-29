/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:33:31 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 18:40:19 by honguyen         ###   ########.fr       */
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
	long		nbr;
	long		index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void		set_index(t_stack *stk_a, int i);
void		indexing_stack(t_stack *stk_a);
t_stack		*write_stack(char *str);
t_stack		*write2stack(int agc, char **agv);
void		ft_sort_three(t_stack **a);
void    	sort_stack(t_stack **a);
t_stack		**ft_sort_a(t_stack **a, t_stack **b);
int	ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c);
int	ft_rotate_type_ba(t_stack *a, t_stack *b);
int	ft_find_index(t_stack *a, int nbr);
int	ft_find_place_b(t_stack *stack_b, int nbr_push);
int	ft_find_place_a(t_stack *stack_a, int nbr_push);
int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void  		ft_raxn(t_stack **a, int min);
void  		ft_rraxn(t_stack **a, int min);
void		ft_min2top(t_stack **a, int min);
void		ft_sa(t_stack **a, int j);
void		ft_sb(t_stack **b, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **a, t_stack **b, int j);
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_rrb(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);
void		ft_rrr_sub(t_stack **b, int j);
int  		check_invalid(t_stack *a);
int			check_sorted(t_stack *a);
int			check_inv_cons(t_stack *st);
void		msg_err(void);
void		free_stack(t_stack **stack_a);
void		free_arr(char **ar_str);
t_stack		*stack_last(t_stack *lst);
t_stack		*stack_new_node(int  nbr);
void		stack_add_back(t_stack **a, t_stack *new_node);
int			size_stack(t_stack *stk);
int			index_min(t_stack *a, int min);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
void		stack_printf(t_stack *st_a);//
#endif