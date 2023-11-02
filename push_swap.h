/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:50 by martorre          #+#    #+#             */
/*   Updated: 2023/11/02 15:01:19 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_moves
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_moves;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

int			ft_error_test(int argc, char **argv, t_stack *stack_a);
t_stack		*ft_save_num(int argc, char **argv, t_stack *stack_a, int i);
int			ft_list_size(t_stack *lst);
void		ft_lstfree(t_stack **stack_a);
t_stack		*reverse_rotate(t_stack *stack);
t_stack		*rra_reverse_rotate(t_stack *stack_a);
t_stack		*rrb_reverse_rotate(t_stack *stack_b);
void		rrr_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*rotate(t_stack *stack);
t_stack		*ra_rotate(t_stack *stack_a);
t_stack		*rb_rotate(t_stack *stack_b);
void		rr_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*swap(t_stack *stack); 
t_stack		*sa_swap(t_stack *stack_a);
t_stack		*sb_swap(t_stack *stack_b);
void		ss_swap(t_stack **stack_a, t_stack **stack_b);
t_stack		*push(t_stack *stack, t_stack **add);
void		pa_push(t_stack **stack_a, t_stack **stack_b);
void		pb_push(t_stack **stack_a, t_stack **stack_b);
void		two_nums(t_stack **stack);
void		three_nums(t_stack **stack);
void		four_nums(t_stack **stack, t_stack **stack_b);
int			find_min(t_stack *stack, int *pos);
int			find_max(t_stack *stack, int *auxpos);
void		five_nums(t_stack **stack, t_stack **stack_b);
void		len_stack(t_stack **stack_a, t_stack **stack_b);
void		sort_all(t_stack **stack_a, t_stack **stack_b);
void		ft_free_split( char **mat);
t_moves		init_moves(void);
int			is_sorted(t_stack *stack_a);
void		print_stacks (t_stack *stack_a, t_stack *stack_b);
void		do_rrb(t_stack **stack_b, t_moves moves);
void		do_rra(t_stack **stack_a, t_moves moves);
void		do_rb(t_stack **stack_b, t_moves moves);
void		do_ra(t_stack **stack_a, t_moves moves);
void		doit_pa(t_stack **stack_a, t_stack **stack_b);
void		doit_rrb(t_stack **stack_b);
int			pos_num(int num, t_stack *stack_b);
void		do_rbra_or_rrbrra(t_stack **stack_a, t_stack **stack_b);
t_moves		calc_best_move(t_stack *stack_a, t_stack *stack_b);
t_moves		check_rr_rrr(t_moves moves);


#endif