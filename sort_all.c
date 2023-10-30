/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:57 by martorre          #+#    #+#             */
/*   Updated: 2023/10/30 19:35:59 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int find_max(t_stack *stack, int *auxpos)
{
	int 	max;
	int 	pos;

	max = stack->content;
	pos = 0;
	*auxpos = 0;
	while (stack != NULL)
	{
		if (stack->content > max)
		{
			max = stack->content;
			*auxpos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max);
}

int	pos_num(int num, t_stack *stack_b)
{
	int		pos;
	int		auxpos;
	int		aux;

	pos = 0;
	auxpos = 0;
	aux = 0;

	if (num < find_min(stack_b, &pos))
		return (pos);
	pos = 0;
	while (stack_b != NULL)
	{
		if (num > (stack_b)->content && aux < (stack_b)->content)
		{
			aux = (stack_b)->content;
			auxpos = pos;
		}
		stack_b = (stack_b)->next;
		pos++;
	}
	return (auxpos);
}

int	is_sorted(t_stack *stack_a)
{
	int	out;

	out = 0;
	while (stack_a->next != NULL && out == 0)
	{
		if (stack_a->content < stack_a->next->content)
			out = 0;
		else
			out = 1;
		stack_a = stack_a->next;
	}
	return (out);
}

t_moves	*calc_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_moves	*moves;
	int		i;

	i = 0;
	moves = malloc(sizeof(t_moves));
	if (!moves)
		return (0);
	moves->rb = pos_num(stack_a->content, stack_b);
	//(void) stack_a;
	//(void) stack_b;
	return (moves);
}
int	do_rotate(t_stack *stack_a, t_stack *stack_b, t_moves *moves)
{
	int		i;

	i = 0;
	while (stack_a != NULL)
	{
		i = 0;
		moves = calc_best_move (stack_a, stack_b);
		if (!moves)
			return (0);
		while (moves->rb > i)
		{
			rb_rotate (stack_b);
			i++;
		}
		pb_push(stack_a, stack_b);
		stack_a = stack_a->next;
	}
	return (0);
}

int	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	t_moves *moves = NULL;
	t_stack	*tmp;
	moves = calc_best_move(*stack_a, *stack_b);
	tmp = *stack_a;
	if (is_sorted(*stack_a) == 1)
	{
		pb_push(stack_a, stack_b);
		pb_push(stack_a, stack_b); 
		do_rotate(*stack_a, *stack_b, moves);
	}
	return (0);
}
