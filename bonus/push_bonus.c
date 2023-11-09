/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:53:42 by martorre          #+#    #+#             */
/*   Updated: 2023/11/09 10:49:34 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./push_swap_bonus.h"

t_stack	*push(t_stack *stack_a, t_stack **add)
{
	t_stack	*aux;

	aux = stack_a;
	aux = (*add);
	(*add) = (*add)->next;
	aux->next = stack_a;
	return (aux);
}

void	pa_push(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_b) > 0)
		*stack_a = push(*stack_a, stack_b);
}

void	pb_push(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) > 0)
		*stack_b = push(*stack_b, stack_a);
}
