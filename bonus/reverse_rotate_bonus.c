/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:05:18 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 19:10:27 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./push_swap_bonus.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = NULL;
	aux = stack;
	while (stack->next->next != NULL)
		stack = stack->next;
	tmp = stack->next;
	tmp->next = aux;
	stack->next = NULL;
	return (tmp);
}

t_stack	*rra_reverse_rotate(t_stack *stack_a)
{
	return (reverse_rotate(stack_a));
}

t_stack	*rrb_reverse_rotate(t_stack *stack_b)
{
	return (reverse_rotate(stack_b));
}

void	rrr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = reverse_rotate(*stack_a);
	*stack_b = reverse_rotate(*stack_b);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_moves moves)
{
	while (moves.rrr > 0)
	{
		rrr_rotate(stack_a, stack_b);
		moves.rrr--;
	}
}
