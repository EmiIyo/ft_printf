/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:31:39 by eiscan            #+#    #+#             */
/*   Updated: 2022/04/15 12:31:40 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long long a)
{
	int	len;

	len = 0;
	while (a != 0)
	{
		a /= 16;
		len++;
	}
	return (len);
}

void	ft_put_hexx(unsigned long long n)
{
	if (n >= 16)
	{
		ft_put_hexx(n / 16);
		ft_put_hexx(n % 16);
	}
	else
	{
		if (n > 9)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + 48);
	}
}

int	ft_print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (n == 0)
		len += write(1, "0", 1);
	else
		ft_put_hexx(n);
	return (hex_len(n) + len);
}
