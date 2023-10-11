/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:16:38 by martorre          #+#    #+#             */
/*   Updated: 2023/10/11 19:42:05 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	its_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\t' || str[i] == '\n')
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
	if (str[i] == '-')
		sig *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	ft_dup_test(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ft_putstr("Error\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error_test(int argc, char **argv)
{
	int	i;

	i = 1;
	//if (argc == 2)
		//ft_str_test(argv);
	//else
	//{
		while (i < argc)
		{
			if ((argv[i]) == 1)
				return (ft_putstr("Error\n"), 1);
			i++;
		}
		ft_dup_test(argc, argv);
	//}
	return (0);
}

// CASO ./push_swap "1 1":
//		NO ES NECESARIO CONTROLANDOLO NI NUNCA
//		AHORA BIEN SI QUIERES QUE TE AYUDE EN ESTE EJERCICIO YA LO PUEDES ESTAR HACIENDO
//		ES TAN FACIL COMO SI EL ARGC == 2 ARGV[1] = SPLIT Y USAR EL METODO DEL ARGV NORMAL
//		!!!!!!! NO LO HAGAS AHORA !!!!!!!!!!!!!
//		PUES CUANDO TE FUNCIONE EL NORMAL????? ES PA BI LA ARGC > 2 es decit ./push_swap 1 4 2 8 7
//		CONTROLAR MAXIMOS I MINIMOS 