/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:24:57 by martorre          #+#    #+#             */
/*   Updated: 2023/11/02 15:32:25 by martorre         ###   ########.fr       */
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
		do_rb(stack_b, moves);
		do_rrb(stack_b, moves);
		do_ra(stack_a, moves);
		do_rra(stack_a, moves);
		pb_push(stack_a, stack_b);
	}
}
t_moves	calc_moves(t_moves moves, int i, t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;
	int	pos;

	len_a = ft_list_size(stack_a);
	len_b = ft_list_size(stack_b);
	pos = pos_num(stack_a->content, stack_b);
	if (i < (len_a / 2))
		moves.ra = i;
	else
		moves.rra = len_a - i;
	if (pos < (len_b / 2))
		moves.rb = pos;
	else
		moves.rrb = len_b - pos;
	moves.total = moves.ra + moves.rb + moves.rra + moves.rrb;
	return (moves);
}

t_moves	calc_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_moves	moves;
	t_moves	aux;
	int		pos;
	int		i;

	aux = init_moves();
	pos = 0;
	i = 0;
	while (stack_a != NULL)
	{
		moves = init_moves();
		moves = calc_moves(moves, i, stack_a, stack_b);
		moves = check_rr_rrr(moves);
		if (moves.total < aux.total)
			aux = moves;
		stack_a = stack_a->next;
		i++;
	}
	return (aux);
}
