/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:05:18 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 19:06:08 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	int		len;
	t_stack	*tmp = NULL;

	len = ft_listsize(stack);
	if (len > 1)
	{
		tmp = stack->next;
		ft_listadd_front(&tmp, stack);
	}
	return (tmp);
}

void	rra_reverse_rotate(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb__reverse_rotate(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}