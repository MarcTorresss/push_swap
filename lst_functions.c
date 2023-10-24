/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:52:12 by martorre          #+#    #+#             */
/*   Updated: 2023/10/24 14:59:30 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
//REACER !!!!
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
void	ft_list_add_back(t_stack **lst, t_stack *new)
{
	if ((*lst))
	{
		if (new)
			ft_last_list_value(*lst)->next = new;
	}
	else
		(*lst) = new;
}

void	ft_list_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_last_list_value(t_stack *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (0);
}