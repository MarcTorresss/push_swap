/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:52:12 by martorre          #+#    #+#             */
/*   Updated: 2023/10/23 16:53:11 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	ft_listsize(t_stack *lst)
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
void	ft_listadd_back(t_stack **lst, t_stack *new)
{
	if ((*lst))
	{
		if (new)
			ft_listlast(*lst)->next = new;
	}
	else
		(*lst) = new;
}

void	ft_listadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_listlast(t_stack *lst)
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