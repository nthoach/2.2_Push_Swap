/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:33:31 by marvin            #+#    #+#             */
/*   Updated: 2024/02/07 15:27:29 by honguyen         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

void	fn_apply_move(t_stack **a, t_stack **b, char	*mv, int *msg_err);
void	fn_check(t_stack	**a, char *mv, int *err);

t_stack	*fn_writestack(int agc, char **agv, int *err);
t_stack	*fn_writestack2(int agc, char **agv, t_stack **a, int *err);
t_stack	*fn_writestack1(char *str, int *err);
int		ft_atoi_ps(const char *str, int *err);
void	fn_index_stack(t_stack *st_a);
void	fn_set_index(t_stack *st_a, size_t i);

void	fn_sort(t_stack **a);
t_stack	**fn_best_pusha(t_stack **a, t_stack **b);
void	fn_sort_three(t_stack **a);

int		fn_best_rotate(t_stack *st_a, t_stack *st_b);
int		fn_rr_pa(t_stack *st_a, t_stack *st_b, int nbr);
int		fn_rrr_pa(t_stack *st_a, t_stack *st_b, int nbr);
int		fn_rarrb_pa(t_stack *st_a, t_stack *st_b, int nbr);
int		fn_rrarb_pa(t_stack *st_a, t_stack *st_b, int nbr);

int		fn_apply_rarrb(t_stack **a, t_stack **b, int nbr);
int		fn_apply_rrarb(t_stack **a, t_stack **b, int nbr);
int		fn_apply_rrr(t_stack **a, t_stack **b, int nbr);
int		fn_apply_rr(t_stack **a, t_stack **b, int nbr);

int		fn_checkduplicate(t_stack *st_a);
int		fn_checksorted(t_stack *st_a);

void	msg_err(void);
void	fn_freestack(t_stack **a);
void	fn_freearr(char **arr_str);

void	fn_sa(t_stack **a, int j);
void	fn_sb(t_stack **b, int j);
void	fn_ss(t_stack **a, t_stack **b, int j);
void	fn_pa(t_stack **a, t_stack **b, int j);
void	fn_pb(t_stack **a, t_stack **b, int j);
void	fn_ra(t_stack **a, int j);
void	fn_rb(t_stack **b, int j);
void	fn_rr(t_stack **a, t_stack **b, int j);
void	fn_rra(t_stack **a, int j);
void	fn_rrb(t_stack **b, int j);
void	fn_rrr(t_stack **a, t_stack **b, int j);

int		fn_findmin(t_stack *st_a);
int		fn_findmax(t_stack *st_a);
t_stack	*fn_move2last(t_stack *st_a);
t_stack	*fn_newnode(int nbr);
void	fn_add2last(t_stack **a, t_stack *new_node);
int		fn_size(t_stack *st_a);
int		fn_findlocation(t_stack *st_a, int idx);
int		fn_find_loc(t_stack *st_a, int nbr);
int		fn_find_loc_b(t_stack *st_b, int nbr_push);
int		fn_find_loc_a(t_stack *st_a, int nbr_push);

#endif