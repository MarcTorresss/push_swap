/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:05:18 by martorre          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:39 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	aux = stack;
	while (stack != NULL)
	{
		if (stack->next == NULL)
			tmp = stack;
		stack = stack->next;
	}
	tmp->next = aux;
	//aux->next = NULL;
	while (aux != NULL)
	{
		if (aux->next != NULL)		
			aux->next = NULL;
		aux = aux->next;
	}
	return (tmp);
}

t_stack	*rra_reverse_rotate(t_stack *stack_a)
{
	ft_printf("rra\n");
	return (reverse_rotate(stack_a));
}

t_stack	*rrb__reverse_rotate(t_stack *stack_b)
{
	ft_printf("rrb\n");
	return (reverse_rotate(stack_b));
}

void	rrr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	//COMPROVAR
	*stack_a = reverse_rotate(*stack_a);
	*stack_b = reverse_rotate(*stack_b);
	ft_printf("rrr\n");
}