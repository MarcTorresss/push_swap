/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:54:27 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 19:10:24 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./push_swap_bonus.h"

t_stack	*rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	aux = stack;
	tmp = stack->next;
	while (stack->next != NULL)
		stack = stack->next;
	stack->next = aux;
	aux->next = NULL;
	return (tmp);
}

t_stack	*ra_rotate(t_stack *stack_a)
{
	return (rotate(stack_a));
}

t_stack	*rb_rotate(t_stack *stack_b)
{
	return (rotate(stack_b));
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, t_moves moves)
{
	while (moves.rr > 0)
	{
		rr_rotate(stack_a, stack_b);
		moves.rr--;
	}
}
