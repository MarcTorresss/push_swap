/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:53:42 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 19:06:15 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*push(t_stack *stack, t_stack *add)
{
	int	len;

	len = ft_listsize(add);
	if (len > 0)
		ft_listadd_front(&stack, add);
	return (stack);
}

void	pa_push(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a,stack_b);
	ft_printf("pa\n");
}

void	pb_push(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b,stack_a);
	ft_printf("pb\n");
}