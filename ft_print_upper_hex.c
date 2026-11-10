/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:25:55 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:25:57 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_hex(unsigned int a)
{
	int	count;

	count = 0;
	if (a /  16 > 0)
		count += print_hex(a / 16);
	count += write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (count);
}

int	ft_print_adress(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	return (print_hex(n));
}

