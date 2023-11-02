/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:19:53 by martorre          #+#    #+#             */
/*   Updated: 2023/11/02 13:15:53 by martorre         ###   ########.fr       */
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

void	four_nums(t_stack **stack, t_stack **stack_b)
{
	int	posmin;
	int	i;
	
	find_min(*stack, &posmin);
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
	
	find_min(*stack, &posmin);
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

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (is_sorted(*stack_a) == 1)
	{
		pb_push(stack_a, stack_b);
		pb_push(stack_a, stack_b);
		do_rbra_or_rrbrra(stack_a, stack_b);
		//doit_rrb(stack_b);
		//doit_pa(stack_a, stack_b);
	}
}