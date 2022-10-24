/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:43:40 by czorraqu          #+#    #+#             */
/*   Updated: 2022/10/21 17:08:17 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
