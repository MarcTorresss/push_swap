/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:15:04 by martorre          #+#    #+#             */
/*   Updated: 2023/10/31 15:09:45 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	do_rb(t_stack **stack_b, t_moves moves)
{
	while (moves.rb > 0)
	{
		(*stack_b) = rb_rotate(*stack_b);
		moves.rb--;
	}
}

void	do_ra(t_stack **stack_a, t_moves moves)
{
	while (moves.ra > 0)
	{
		(*stack_a) = ra_rotate(*stack_a);
		moves.ra--;
	}
}

void	do_rrb(t_stack **stack_b, t_moves moves)
{
	while (moves.rrb > 0)
	{
		(*stack_b) = rrb_reverse_rotate(*stack_b);
		moves.rrb--;
	}
}

void	do_rra(t_stack **stack_a, t_moves moves)
{
	while (moves.rra > 0)
	{
		(*stack_a) = rra_reverse_rotate(*stack_a);
		moves.rra--;
	}
}
