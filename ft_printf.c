/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:54:39 by czorraqu          #+#    #+#             */
/*   Updated: 2022/10/21 18:20:28 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_check_arg(va_list arguments, char type)
{
	int	result;

	result = 0;
	if (type == 'c')
		result += ft_putchar(va_arg(arguments, int));
	else if (type == 's')
		result += ft_putstr(va_arg(arguments, char *));
	else if (type == 'i' || type == 'd')
		result += ft_putnbr(va_arg(arguments, int), result);
	else if (type == 'u')
		result += ft_putnbr(va_arg(arguments, unsigned int), result);
	else if (type == 'x' || type == 'X')
		result += ft_putnbr_base(va_arg(arguments, unsigned int), type);
	else if (type == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		result = ft_putptr(va_arg(arguments, unsigned long long));
		if (result != -1)
			result += 2;
	}
	else if (type == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(char const *str, ...)
{
	va_list	arguments;
	int		i;
	int		result;
	int		temp;

	va_start (arguments, str);
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			temp = ft_putchar(str[i]);
		}
		else
		{
			temp = ft_check_arg(arguments, str[++i]);
		}
		i++;
		if (temp == -1)
			return (-1);
		result += temp;
	}
	va_end (arguments);
	return (result);
}

// int main()
// {
// 	int	i;
// 	int *ptr;

// 	i = 8;
// 	ptr = &i;
// 	ft_printf("%p\n", ptr);
// 	printf("%p\n", ptr);

// }
