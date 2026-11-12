/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:19:42 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 13:59:04 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex(size_t a, char *base)
{
	int	count;

	count = 0;
	if (a >= 16)
	{
		count = print_hex(a / 16, base);
		if (count == -1)
			return (-1);
	}
	if (write(1, &base[a % 16], 1) == -1)
		return (-1);
	return (++count);
}

int	print_lower_x(va_list *args)
{
	return (print_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
}

int	print_upper_x(va_list *args)
{
	return (print_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
}

int	print_addr(va_list *args)
{
	size_t	n;
	int		tmp;

	n = (size_t)va_arg(*args, void *);
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (write(1, "0x", 2) == -1)
		return (-1);
	tmp = print_hex(n, "0123456789abcdef");
	if (tmp == -1)
		return (-1);
	return (2 + tmp);
}
