/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:54:27 by martorre          #+#    #+#             */
/*   Updated: 2023/10/24 14:21:22 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft/libft.h"

t_stack	*rotate(t_stack *stack)
{
	int		len;
	t_stack	*tmp = NULL;

	len = ft_list_size(stack);
	if (len > 0)
	{
		tmp = stack->next; // TMP TIENE LA SEGUNDA UBI DE STACK I ESTA APUNTANDO A STACK 
		stack->next = NULL; // STACK NO ESTA APUNTANDO A NADA POR LO TANTO QUE APUNTE A NULL
		ft_list_add_back(&tmp, stack);
	}
	return (tmp);
}

t_stack	*ra_rotate(t_stack *stack_a)
{
	ft_printf("ra\n");
	return (rotate(stack_a));
}

t_stack	*rb_rotate(t_stack *stack_b)
{
	ft_printf("rb\n");
	return (rotate(stack_b));
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
	ft_printf("rr\n");
}