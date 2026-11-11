/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:27:35 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/11 09:19:47 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr(unsigned int a)
{
	int	count;

	count = 0;
	if (a / 10 > 0)
		count += ft_putnbr(a / 10);
	count += write(1, &"0123456789"[a % 10], 1);
	return (count);
}

int	ft_print_unsigned_decimal(va_list *args)
{
	unsigned int	a;

	a = va_arg(*args, unsigned int);
	return (ft_putnbr(a));
}
