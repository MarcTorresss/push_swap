/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:26:34 by martorre          #+#    #+#             */
/*   Updated: 2023/10/25 18:58:36 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	if (ft_error_test(argc, argv, stack_a) == 0)
	{
		if (argc == 1)
			return (0);
		if (argc == 3)
			two_nums(&stack_a);
		else if (argc == 4)
			three_nums(&stack_a);
		else if (argc == 5)
			four_nums(&stack_a);
	}
		//stack_a = ra_rotate(stack_a);
		//printf("MOVES\n");
		/*stack_a = sa_sawp(stack_a);
		pb_push(&stack_a, &stack_b);
		pb_push(&stack_a, &stack_b);
		pb_push(&stack_a, &stack_b);
		rr_rotate(&stack_a, &stack_b);
		rrr_rotate(&stack_a, &stack_b);
		stack_a = sa_sawp(stack_a);
		pa_push(&stack_a, &stack_b);
		pa_push(&stack_a, &stack_b);
		pa_push(&stack_a, &stack_b);*/
		/*printf("\nStack A\n");
		while (stack_a != NULL)
		{

			printf("%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
		printf("\nStack B\n");
		while (stack_b != NULL)
		{
			printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}*/
}