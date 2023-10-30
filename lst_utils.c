/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:02 by martorre          #+#    #+#             */
/*   Updated: 2023/10/30 11:24:22 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_lstfree(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*stack_a);
		*stack_a = tmp;
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
				return (ft_lstfree(&tmp), NULL);
		}
		else
			stack_a->next = NULL;
		stack_a = stack_a->next;
		i++;
	}
	return (tmp);
}

int	ft_list_size(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void ft_free_split( char **mat)
{
	int i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}