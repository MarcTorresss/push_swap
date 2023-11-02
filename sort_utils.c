/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:30:17 by martorre          #+#    #+#             */
/*   Updated: 2023/10/31 14:43:07 by martorre         ###   ########.fr       */
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

void doit_rrb(t_stack **stack_b)
{
	int	pos;
	int	len;
	int	res;
	int	i;

	pos = 0;
	len = ft_list_size(*stack_b);
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
	moves.total = INT_MAX;
	return (moves);
}

int find_max(t_stack *stack, int *auxpos)
{
	int 	max;
	int 	pos;

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

int	is_sorted(t_stack *stack_a)
{
	int	out;

	out = 0;
	while (stack_a->next != NULL && out == 0)
	{
		if (stack_a->content < stack_a->next->content)
			out = 0;
		else
			out = 1;
		stack_a = stack_a->next;
	}
	return (out);
}
