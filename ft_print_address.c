/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:28:44 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:28:46 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_hex(unsigned long a)
{
	int	count;

	count = 0;
	if (a /  16 > 0)
		count += print_hex(a / 16);
	count += write(1, &"0123456789abcdef"[a % 16], 1);
	return (count);
}

int	ft_print_adress(va_list *args)
{
	unsigned long	n;

	n = (unsigned long)va_arg(*args, void *);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + print_hex(n));
}
