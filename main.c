/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:26:34 by martorre          #+#    #+#             */
/*   Updated: 2023/10/11 18:27:23 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*p_list	ft_save_num(int argc, char **argv, p_list *stack_a)
{
	p_list	*tmp;
	int	i;

	i = 1;
	tmp = stack_a;
	while (i < argc)
	{
		stack_a->content = ft_atoi(argv[i]);
		stack_a->next = malloc(sizeof(p_list));
		if (!stack_a->next)
			//return (ft_lstclear(&tmp, del), NULL);
		stack_a = stack_a->next;
	}
	return (tmp);
}*/

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	ft_error_test(argc, argv);
	
	//ft_save_num(argc, argv, stack_a, );
}