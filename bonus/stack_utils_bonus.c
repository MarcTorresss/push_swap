/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:32 by martorre          #+#    #+#             */
/*   Updated: 2023/11/08 19:09:22 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./push_swap_bonus.h"

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
