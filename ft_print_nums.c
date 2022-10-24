/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:15:18 by czorraqu          #+#    #+#             */
/*   Updated: 2022/10/21 18:16:47 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int n, int res)
{
	if (n < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		res++;
		n = -n;
	}
	if (n > 9)
		res = ft_putnbr(n / 10, res);
	if (res == -1)
		return (-1);
	if (write(1, &"0123456789"[n % 10], 1) != 1)
		return (-1);
	res++;
	return (res);
}

int	ft_putnbr_base(unsigned int n, char c)
{
	char	*hexadeci;
	int		res;
	int		temp;

	hexadeci = "0123456789abcdef";
	if (c == 'X')
		hexadeci = "0123456789ABCDEF";
	res = 0;
	temp = 0;
	if (n > 15)
	{
		temp = ft_putnbr_base(n / 16, c);
		if (temp == -1)
			return (-1);
		res += temp;
	}
	temp = ft_putchar((hexadeci[n % 16]));
	if (temp == -1)
		return (-1);
	res += temp;
	return (res);
}

int	ft_putptr(unsigned long long ptr)
{
	char	*hexadeci;
	int		res;
	int		temp;

	hexadeci = "0123456789abcdef";
	res = 0;
	temp = 0;
	if (ptr > 15)
	{
		temp = ft_putptr(ptr / 16);
		if (temp == -1)
			return (-1);
		res += temp;
	}
	temp = ft_putchar((hexadeci[ptr % 16]));
	if (temp == -1)
		return (-1);
	res += temp;
	return (res);
}
