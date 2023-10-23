/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:50 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 19:23:17 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

int			ft_error_test(int argc, char **argv, t_stack *stack_a);
t_stack		*ft_save_num(int argc, char **argv, t_stack *stack_a, int i);
int			ft_listsize(t_stack *lst);
void		ft_listadd_back(t_stack **lst, t_stack *new);
void		ft_listadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_listlast(t_stack *lst);
t_stack		*reverse_rotate(t_stack *stack);
void		rra_reverse_rotate(t_stack *stack_a);
void		rrb__reverse_rotate(t_stack *stack_b);
void		rrr_rotate(t_stack *stack_a, t_stack *stack_b);
t_stack		*rotate(t_stack *stack);
t_stack		*ra_rotate(t_stack *stack_a);
t_stack		*rb_rotate(t_stack *stack_b);
void		rr_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*swap(t_stack *stack);
void		sa_sawp(t_stack *stack_a);
void		sb_swap(t_stack *stack_b);
void		ss_swap(t_stack *stack_a, t_stack *stack_b);
t_stack		*push(t_stack *stack, t_stack *add);
void		pa_push(t_stack *stack_a, t_stack *stack_b);
void		pb_push(t_stack *stack_a, t_stack *stack_b);

#endif