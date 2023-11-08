/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:52:05 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 13:16:55 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./push_swap.h"

t_stack	*swap(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (ft_stack_size(stack) > 0)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	return (stack);
}

t_stack	*sa_swap(t_stack *stack_a)
{
	ft_printf("sa\n");
	return (swap(stack_a));
}

t_stack	*sb_swap(t_stack *stack_b)
{
	ft_printf("sb\n");
	return (swap(stack_b));
}

void	ss_swap(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = swap(*stack_a);
	*stack_b = swap(*stack_b);
	ft_printf("ss\n");
}
