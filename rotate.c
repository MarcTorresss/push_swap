/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:54:27 by martorre          #+#    #+#             */
/*   Updated: 2023/10/25 19:49:40 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	aux = stack;
	tmp = stack->next;
	if (ft_list_size(stack) > 0)
	{
		while (stack->next != NULL)
			stack = stack->next;
		stack->next = aux;
		aux->next = NULL;
	}
	return (tmp);
}

t_stack	*ra_rotate(t_stack *stack_a)
{
	ft_printf("ra\n");
	return (rotate(stack_a));
}

t_stack	*rb_rotate(t_stack *stack_b)
{
	ft_printf("rb\n");
	return (rotate(stack_b));
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
	ft_printf("rr\n");
}
