/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:19:53 by martorre          #+#    #+#             */
/*   Updated: 2023/10/26 11:54:20 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	two_nums(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_swap(*stack);
}

void	three_nums(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_swap(*stack);
	if ((*stack)->next->content > (*stack)->next->next->content)
		(*stack) = rra_reverse_rotate(*stack);
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_swap(*stack);
}

int find_min(t_stack *stack)
{
	int 	min;
	int 	pos;
	int		auxpos;

	min = stack->content;
	pos = 0;
	auxpos = 0;
	while (stack != NULL)
	{
		if (stack->content < min)
		{
			min = stack->content;
			auxpos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (auxpos);
}

void	four_nums(t_stack **stack, t_stack **stack_b)
{
	int	posmin;
	int	i;
	
	posmin = find_min(*stack);
	i = 0;
	while (i < posmin)
	{
		(*stack) = ra_rotate(*stack);
		i++;
	}
	pb_push(stack, stack_b);
	three_nums(stack);
	pa_push(stack, stack_b);
}

void	five_nums(t_stack **stack, t_stack **stack_b)
{
	int	posmin;
	int	i;
	
	posmin = find_min(*stack);
	i = 0;
	while (i < posmin)
	{
		(*stack) = ra_rotate(*stack);
		i++;
	}
	pb_push(stack, stack_b);
	four_nums(stack, stack_b);
	pa_push(stack, stack_b);
}
