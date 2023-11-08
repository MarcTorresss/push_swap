/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:02 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 17:18:07 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_stack_free(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
}

t_stack	*ft_save_num(int limit, char **str, t_stack *stack_a, int i)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (i < limit)
	{
		stack_a->content = ft_atoi(str[i]);
		if (i != limit - 1)
		{
			stack_a->next = malloc(sizeof(t_stack));
			if (!stack_a->next)
				return (ft_stack_free(&tmp), NULL);
		}
		else
			stack_a->next = NULL;
		stack_a = stack_a->next;
		i++;
	}
	return (tmp);
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_free_split(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

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
