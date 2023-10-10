/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:01:37 by martorre          #+#    #+#             */
/*   Updated: 2023/10/02 18:26:06 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversations(char c, va_list arg_ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg_ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg_ptr, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_free_itoa(va_arg(arg_ptr, int)));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF",
				42));
	else if (c == 'u')
		return (ft_free_nosig(va_arg(arg_ptr, int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789abcdef",
				42));
	else if (c == 'p')
	{
		return (ft_putnbr_hex_v(va_arg(arg_ptr, unsigned long),
				"0123456789abcdef", testprint()));
	}
	return (0);
}

int	start(char *str, int out, int cont, va_list arg_ptr)
{
	int	i;

	i = -1;
	while (str[++i] && out != -1)
	{
		if (str[i] != '%')
		{
			out = ft_putchar(str[i]);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
		if (str[i] == '%' && out != -1)
		{
			out = conversations(str[++i], arg_ptr);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
	}
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg_ptr;
	int		out;
	int		cont;

	out = 0;
	cont = 0;
	va_start(arg_ptr, str);
	cont = start((char *)str, out, cont, arg_ptr);
	return (cont);
}
// int	main(void)
//{
/*char	*hola;

hola = "ALOOOOS";
printf(NULL);
printf("MIO => %d\n",ft_printf("Mio -> He2llo, %s! The answer is %d.\n",
		"world", 42));
printf("ORG => %d\n",printf("Org -> He2llo, %s! The answer is %d.\n",
		"world", 42));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%c\n", 'w'));
printf("ORG => %d\n",printf("Org ->%c\n", 'w'));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%s\n", hola));
printf("ORG => %d\n",printf("Org ->%s\n", hola));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%p\n", hola));
printf("ORG => %d\n",printf("Org ->%p\n",hola));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%d\n", 10));
printf("ORG => %d\n",printf("Org ->%d\n", 10));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%i\n", 11));
printf("ORG => %d\n",printf("Org ->%i\n", 11));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%u\n", 11));
printf("ORG => %d\n",printf("Org ->%u\n", 11));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%x\n", 23456777));
printf("ORG => %d\n",printf("Org ->%x\n", 23456777));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%X\n", 9));
printf("ORG => %d\n",printf("Org ->%X\n", 9));
ft_printf("\n");
printf("MIO => %d\n",ft_printf("Mio ->%%\n"));
printf("ORG => %d\n",printf("Org ->%%\n"));
printf("OG => %d\n",printf(" %c %c %c ", '0', 0, '1'));
printf("MIO => %d\n",ft_printf(" %c %c %c ", '0', 0, '1'));
printf("ORG => %d\n",printf(" %i ", -100));
printf("MIO => %d\n",ft_printf(" %i ", -100));*/
//	void	*c = "-16474523";
//	printf("MIO => %d\n",ft_printf("Mio ->%p\n", c));
//	printf("ORG => %d\n",printf("Org ->%p\n", c));
//}
/*
#include <stdarg.h>
#include <stdio.h>
int	sum(int, ...);
int	main(void)
{
   printf("15 Hola 56 Adeu 10 dg= %d\n",  sum(3, 15, 56, 10) );
   return (0);
}

int	sum(int num_args, ...)
{
   int val = 0;
   va_list ap;
   int i;

   va_start(ap, num_args);
   for(i = 0; i < num_args; i++)
   {
		val += va_arg(ap, int);
   }
   va_end(ap);
   return (val);
}*/