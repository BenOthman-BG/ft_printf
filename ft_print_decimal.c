/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:27:06 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:27:07 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr(long a)
{
	int	count;

	count = 0;
	if (a / 10 > 0)
		count += ft_putnbr(a / 10);
	count += write(1, &"0123456789"[a % 10], 1);
	return (count);
}

int	ft_print_decimal(va_list *args)
{
	long	a;
	int		len;

	a = va_arg(*args, int);
	len = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		a = a * (-1);
		len++;
	}
	return (len + ft_putnbr(a));
}
