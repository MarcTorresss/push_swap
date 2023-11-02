/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:02:10 by martorre          #+#    #+#             */
/*   Updated: 2023/10/31 15:40:51 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_moves	calc_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_moves	moves;
	t_moves	aux;
	int		i;
	int		len;
	//len dos stacks
	moves = init_moves();
	len = ft_list_size(stack_b);
	i = 0;
	while (stack_a != NULL)
	{
		if (i < len_a / 2)
			aux.ra = i;
		else
			aux.rra = len_a - i;
		aux_fjkadsjfk = pos_num(stack_a->content, stack_b);
		if (aux_fjkadsjfk < len_b / 2)
			aux.rb = aux_fjkadsjfk;
		else
			aux.rrb = len_b - aux_fjkadsjfk;
		aux.total = aux.ra + aux.rb + aux.rra + aux.rrb;
		if (moves.total > aux.total)
			moves = aux;
		stack_a = stack_a->next;
		i++;
	}
	return (moves);
}