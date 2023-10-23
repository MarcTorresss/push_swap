/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:54:27 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 19:23:43 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*rotate(t_stack *stack)
{
	int		len;
	t_stack	*tmp = NULL;

	len = ft_listsize(stack);
	if (len > 1)
	{
		tmp = stack->next;
		ft_listadd_back(&tmp, stack);
	}
	return (tmp);
}

t_stack	*ra_rotate(t_stack *stack_a)
{
	stack_a = rotate(stack_a);
	ft_printf("ra\n");
	return (stack_a);
}

t_stack	*rb_rotate(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("ra\n");
	return (stack_b);
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
	ft_printf("rr\n");
}