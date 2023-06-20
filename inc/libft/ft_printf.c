/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:36:34 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/18 18:36:29 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

static void	ft_printf_checker(char s, va_list *arg, int *len, int *i)
{
	if (s == 'c')
		ft_putcharacter_len(va_arg (*arg, int), len);
	else if (s == 's')
		ft_string(va_arg (*arg, char *), len);
	else if (s == 'p')
		ft_pointer(va_arg (*arg, size_t), len);
	else if (s == 'i' || s == 'd')
		ft_putnbr_len(va_arg (*arg, int), len);
	else if (s == 'u')
		ft_unsigned_int_len(va_arg (*arg, unsigned int), len);
	else if (s == 'x')
		ft_hexa_len(va_arg (*arg, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexa_len(va_arg (*arg, unsigned int), len, 'X');
	else if (s == '%')
		ft_putcharacter_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start (arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_checker(format[i], &arg, &len, &i);
			i++;
		}
		else
		{
			ft_putcharacter_len((char)format[i], &len);
			i++;
		}
	}
	va_end (arg);
	return (len);
}

/*int	main(void)
{
	char	*str;
	int		i;
	int		value;

	value = 2567;
	str = "Hello";
	i = 65;
	printf("original:\n%s\n%i", str, i);
	ft_printf("mine:\n%s\n%i", str, i);
	printf("Original:\n");
	printf("Decimal value is: %d\n", value);
	printf("Octal value is: %o\n", value);
	printf("Hexadecimal value is (Alphabet in small letters): %x\n", value);
	printf("Hexadecimal value is (Alphabet in capital letters): %X\n", value);
	printf("Mine:\n");
	ft_printf("Decimal value is: %d\n", value);
	ft_printf("Octal value is: %o\n", value);
	ft_printf("Hexadecimal value is (Alphabet in small letters): %x\n", value);
	ft_printf("Hexadecimal value is (Alphabet in capital letters): %X\n", value);
	return (0);
}*/
