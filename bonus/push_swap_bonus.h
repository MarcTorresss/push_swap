/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:05:21 by martorre          #+#    #+#             */
/*   Updated: 2023/11/09 11:01:37 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

int			ft_error_test(int argc, char **argv, t_stack **stack_a);
int			main(int argc, char **argv);
t_stack		*push(t_stack *stack_a, t_stack **add);
void		pa_push(t_stack **stack_a, t_stack **stack_b);
void		pb_push(t_stack **stack_a, t_stack **stack_b);
t_stack		*rra_reverse_rotate(t_stack *stack_a);
t_stack		*rrb_reverse_rotate(t_stack *stack_b);
void		rrr_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*ra_rotate(t_stack *stack_a);
t_stack		*rb_rotate(t_stack *stack_b);
void		rr_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*sa_swap(t_stack *stack_a);
t_stack		*sb_swap(t_stack *stack_b);
void		ss_swap(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_save_num(int limit, char **str, t_stack *stack_a, int i);
void		ft_stack_free(t_stack **stack);
int			ft_stack_size(t_stack *stack);
void		ft_free_split(char **mat);

#endif