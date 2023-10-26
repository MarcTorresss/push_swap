/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:57 by martorre          #+#    #+#             */
/*   Updated: 2023/10/26 12:50:42 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int find_max(t_stack *stack)
{
	int 	max;
	int 	pos;
	int		auxpos;

	max = stack->content;
	pos = 0;
	auxpos = 0;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			auxpos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (auxpos);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int	cont_moves;

	cont_moves = 0;
	pb_push(stack_a, stack_b);
	pb_push(stack_a, stack_b);
	//if ((*stack_a)->content > (*stack_b)->content)
}