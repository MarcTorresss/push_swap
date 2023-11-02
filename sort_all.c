/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:57 by martorre          #+#    #+#             */
/*   Updated: 2023/11/02 13:20:56 by martorre         ###   ########.fr       */
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

void	do_rbra_or_rrbrra(t_stack **stack_a, t_stack **stack_b)
{
	t_moves	moves;
	int		i;

	i = 0;
	moves = init_moves();
	while ((*stack_a) != NULL)
	{
		i = 0;
		moves = calc_best_move (*stack_a, *stack_b);
		if (moves.rb < moves.rrb)
			do_rb(stack_b, moves);
		else
			do_rrb(stack_b, moves);
		if (moves.ra < moves.rra)
			do_ra(stack_a, moves);
		else 
			do_rra(stack_a, moves);
		pb_push(stack_a, stack_b);
	}
}

t_moves	calc_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_moves	moves;
	t_moves	aux;
	int		pos;

	moves = init_moves();
	aux = init_moves();
	pos = 0;
	while (stack_a != NULL)
	{
		pos = pos_num(stack_a->content, stack_b);
		if (pos < (ft_list_size(stack_a) / 2))
			aux.ra = pos;
		else
			aux.rra = ft_list_size(stack_a) - pos;
		if (pos < (ft_list_size(stack_b) / 2))
			aux.rb = pos;
		else
			aux.rrb = ft_list_size(stack_b) - pos;
		aux.total = aux.ra + aux.rb + aux.rra + aux.rrb;
		if (moves.total > aux.total)
			moves = aux;
		stack_a = stack_a->next;
	}
	return (moves);
}
