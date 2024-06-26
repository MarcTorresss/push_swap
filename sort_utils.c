/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:30:17 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 17:17:48 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	doit_pa(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		pa_push(stack_a, stack_b);
	}
}

void	doit_rrb(t_stack **stack_b)
{
	int	pos;
	int	len;
	int	res;
	int	i;

	pos = 0;
	len = ft_stack_size(*stack_b);
	res = 0;
	i = 0;
	find_max(*stack_b, &pos);
	if (len > pos)
	{
		res = len - pos;
		while (i < res)
		{
			*stack_b = rrb_reverse_rotate(*stack_b);
			i++;
		}
	}
}

t_moves	init_moves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rr = 0;
	moves.rrr = 0;
	moves.total = INT_MAX;
	return (moves);
}

int	find_max(t_stack *stack, int *auxpos)
{
	int	max;
	int	pos;

	max = stack->content;
	pos = 0;
	*auxpos = 0;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			*auxpos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max);
}

int	find_min(t_stack *stack, int *auxpos)
{
	int	min;
	int	pos;

	min = stack->content;
	pos = 0;
	*auxpos = 0;
	while (stack != NULL)
	{
		if (stack->content < min)
		{
			min = stack->content;
			*auxpos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min);
}
