/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:26:10 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:26:12 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_hex(unsigned int a)
{
	int	count;

	count = 0;
	if (a /  16 > 0)
		count += print_hex(a / 16);
	count += write(1, &"0123456789abcdef"[a % 16], 1);
	return (count);
}

int	ft_print_lower_address(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_hex(n));
}
