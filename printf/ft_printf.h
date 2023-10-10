/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:27:00 by martorre          #+#    #+#             */
/*   Updated: 2023/10/02 11:06:04 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			conversations(char c, va_list arg_ptr);
int			start(char *str, int out, int cont, va_list arg_ptr);
int			ft_printf(char const *str, ...);
int			ft_putnbr_hex(unsigned int nb, char *base, int out);
int			ft_putnbr_hex_v(unsigned long nb, char *base, int out);
int			ft_withoutsig(const char *str);
char		*ft_nosig(int n);
void		num_utils(unsigned int *num, unsigned int *col_count,
				unsigned int *col_val);
int			testprint(void);
int			cont_digits(unsigned long nb);
int			ft_free_itoa(int n);
int			ft_free_nosig(int n);

#endif