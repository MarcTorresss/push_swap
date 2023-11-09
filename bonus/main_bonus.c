/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:45:15 by martorre          #+#    #+#             */
/*   Updated: 2023/11/09 11:01:14 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./push_swap_bonus.h"

int	is_sorted(t_stack *stack_a)
{
	int	out;

	out = 0;
	while (stack_a->next != NULL && out == 0)
	{
		if (stack_a->content < stack_a->next->content)
			out = 0;
		else
			out = 1;
		stack_a = stack_a->next;
	}
	return (out);
}

int	do_moves(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strcmp(move, "ra\n") == 0)
		*stack_a = ra_rotate(*stack_a);
	else if (ft_strcmp(move, "sa\n") == 0)
		sa_swap(*stack_a);
	else if (ft_strcmp(move, "rra\n") == 0)
		*stack_a = rra_reverse_rotate(*stack_a);
	else if (ft_strcmp(move, "pa\n") == 0)
		pa_push(stack_a, stack_b);
	else if (ft_strcmp(move, "rb\n") == 0)
		*stack_b = rb_rotate(*stack_b);
	else if (ft_strcmp(move, "rrb\n") == 0)
		*stack_b = rrb_reverse_rotate(*stack_b);
	else if (ft_strcmp(move, "sb\n") == 0)
		sb_swap(*stack_b);
	else if (ft_strcmp(move, "pb\n") == 0)
		pb_push(stack_a, stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr_rotate(stack_a, stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr_rotate(stack_a, stack_b);
	else if (ft_strcmp(move, "ss\n") == 0)
		ss_swap(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	check_gtnl(t_stack **stack_a, t_stack **stack_b)
{
	char	*read;
	int		out;

	read = get_next_line(0);
	out = 0;
	while (read != NULL && out == 0)
	{
		if (do_moves(stack_a, stack_b, read) == 0)
		{
			free(read);
			read = get_next_line(0);
		}
		else
			out = 1;
	}
	return (out);
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
		if (check_gtnl(&stack_a, &stack_b) == 0)
		{
			if (is_sorted(stack_a) == 0)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		else
			ft_printf("Error\n");
	}
	ft_stack_free(&stack_a);
}
