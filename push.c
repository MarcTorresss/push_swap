/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:53:42 by martorre          #+#    #+#             */
/*   Updated: 2023/10/24 13:38:28 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*push(t_stack *stack, t_stack **add)
{
	t_stack *aux;

	aux = *add;
	*add = (*add)->next;
	aux->next = stack;
	return (aux);
}

void	pa_push(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	*stack_a = push(*stack_a, stack_b);
}

void	pb_push(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	*stack_b = push(*stack_b, stack_a);
}