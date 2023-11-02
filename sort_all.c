/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:57 by martorre          #+#    #+#             */
/*   Updated: 2023/10/31 15:02:30 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	pos_num(int num, t_stack *stack_b)
{
	int		pos;
	int		auxpos;
	int		aux;

	pos = 0;
	auxpos = 0;
	aux = INT_MIN;

	if (num < find_min(stack_b, &pos))
	{
		find_max(stack_b, &pos);
		return (pos);
	}
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

int	do_rbra_or_rrbrra(t_stack **stack_a, t_stack **stack_b)
{
	t_moves	moves;
	int		i;

	i = 0;
	moves = init_moves();
	while ((*stack_a) != NULL)
	{
		i = 0;
		moves = calc_best_move (*stack_a, *stack_b);
		if (moves.rb < ft_list_size(*stack_b) / 2)
			do_rb(stack_b, moves);
		else
			do_rrb(stack_b, moves);
		if (moves.ra < ft_list_size(*stack_a) / 2)
			do_ra(stack_a, moves);
		else 
			do_rra(stack_a, moves);
		pb_push(stack_a, stack_b);
	}
	return (0);
}

int	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (is_sorted(*stack_a) == 1)
	{
		pb_push(stack_a, stack_b);
		pb_push(stack_a, stack_b);
		do_rbra_or_rrbrra(stack_a, stack_b);
		doit_rrb(stack_b);
		doit_pa(stack_a, stack_b);
	}
	return (0);
}
