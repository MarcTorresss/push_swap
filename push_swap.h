/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:31:50 by martorre          #+#    #+#             */
/*   Updated: 2023/10/11 17:57:45 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_error_test(int argc, char **argv);
//int	ft_int_test(const char *str);

typedef struct s_stack
{
	int				*content;
	struct s_stack	*next;
}					t_stack;

#endif