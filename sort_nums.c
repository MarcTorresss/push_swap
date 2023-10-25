/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:19:53 by martorre          #+#    #+#             */
/*   Updated: 2023/10/25 19:02:33 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	two_nums(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_sawp(*stack);
}

void	three_nums(t_stack **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_sawp(*stack);
	if ((*stack)->next->content > (*stack)->next->next->content)
		(*stack) = rra_reverse_rotate(*stack);
	if ((*stack)->content > (*stack)->next->content)
		(*stack) = sa_sawp(*stack);
}

int find_min(t_stack *stack)
{
	int 	min;
	int 	pos;
	t_stack	*tmp;

	tmp = stack;
	min = stack->content;
	pos = 0;
	while (stack->next != NULL)
	{
		stack= stack->next;
		if (stack->content < min)
			min = stack->content;
	}
	while (tmp->content != min)
	{
		pos++;
		tmp= tmp->next;
	}
	return (pos);
}

void	four_nums(t_stack **stack)
{
	//int	posmin;
	//int	i;
	//posmin = find_min(*stack);
//	i = 0;
	printf("d");
	ra_rotate(*stack);
	/*while ((*stack)->next != NULL)
	{
		printf("%d\n", (*stack)->content);
		(*stack) = (*stack)->next;
	}*/
	/*while (i < posmin)
	{
		(*stack) = ra_rotate(*stack);
		i++;
	}*/
}
