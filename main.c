/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:26:34 by martorre          #+#    #+#             */
/*   Updated: 2023/11/13 12:40:44 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	len_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	len_sack;

	len_sack = ft_stack_size(*stack_a);
	if (is_sorted(*stack_a) == 1)
	{
		if (len_sack == 2)
			two_nums(stack_a);
		else if (len_sack == 3)
			three_nums(stack_a);
		else if (len_sack == 4)
			four_nums(stack_a, stack_b);
		else if (len_sack == 5)
			five_nums(stack_a, stack_b);
		else
			sort_all(stack_a, stack_b);
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nStack A\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nStack B\n");
	while (stack_b != NULL)
	{
		ft_printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	if (ft_error_test(argc, argv, &stack_a) == 0)
	{
		len_stack(&stack_a, &stack_b);
		//print_stacks(stack_a, stack_b);
		ft_stack_free(&stack_a);
	}
}
