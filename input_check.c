/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:16:38 by martorre          #+#    #+#             */
/*   Updated: 2023/11/07 12:14:45 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	its_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}

int	ft_int_test(char *str)
{
	int	i;
	int	sig;

	i = 0;
	sig = 1;
	i = its_space(str);
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\n')
		i++;
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (1);
	if (str[i] == '-')
		sig *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	if (ft_atol(str) <= INT_MAX && ft_atol(str) >= INT_MIN)
		return (0);
	return (1);
}

int	ft_dup_test(int limit, char **str, int i)
{
	int	j;

	j = 0;
	while (i < limit)
	{
		j = i + 1;
		while (j < limit)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_mat_test(char **mat, int qttwords, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < qttwords)
	{
		if (ft_int_test(mat[i]) == 1)
			return (ft_putstr_fd("Error\n", 2), 1);
		i++;
	}
	if (ft_dup_test(qttwords, mat, 0) == 0)
		stack_a = ft_save_num(qttwords, mat, stack_a, 0);
	else
		return (1);
	return (0);
}

int	ft_error_test(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**mat;
	int		qttwords;

	i = 0;
	qttwords = 0;
	if (argc == 2)
	{
		mat = ft_split(argv[1], ' ', &qttwords);
		if (mat == NULL || qttwords == 0)
			return (ft_putstr_fd("Error\n", 2), ft_lstfree(stack_a), 1);
		if (ft_mat_test(mat, qttwords, *stack_a) == 1)
			return (ft_free_split(mat), ft_lstfree(stack_a), 1);
		ft_free_split(mat);
	}
	else
	{
		while (++i < argc)
			if (ft_int_test(argv[i]) == 1)
				return (ft_putstr_fd("Error\n", 2), ft_lstfree(stack_a), 1);
		if (ft_dup_test(argc, argv, 1) == 0)
			*stack_a = ft_save_num(argc, argv, *stack_a, 1);
		else
			return (ft_lstfree(stack_a), 1);
	}
	return (0);
}
