/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:52:05 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 19:06:03 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*swap(t_stack *stack)
{
	int	len;
	int	tmp;

	tmp = 0;
	len = ft_listsize(stack);
	if (len > 1)
	{
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
	}
	return (stack);
}

void	sa_sawp(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb_swap(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}