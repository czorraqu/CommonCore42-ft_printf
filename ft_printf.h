/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czorraqu <czorraqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:17:58 by czorraqu          #+#    #+#             */
/*   Updated: 2022/10/21 18:17:51 by czorraqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long long int n, int res);
int	ft_putnbr_base(unsigned int n, char c);
int	ft_putptr(unsigned long long ptr);
int	ft_check_arg(va_list args, char type);
int	ft_printf(char const *str, ...);

#endif
