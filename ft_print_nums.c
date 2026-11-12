/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:49:35 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 14:02:13 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putnbr(long a)
{
	int	count;

	count = 0;
	if (a >= 10)
	{
		count = ft_putnbr(a / 10);
		if (count == -1)
			return (-1);
	}
	if (write(1, &"0123456789"[a % 10], 1) == -1)
		return (-1);
	return (++count);
}

int	print_d(va_list *args)
{
	long	a;
	int		len;
	int		tmp;

	a = va_arg(*args, int);
	len = 0;
	if (a < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		a = -a;
		len++;
	}
	tmp = ft_putnbr(a);
	if (tmp == -1)
		return (-1);
	return (len + tmp);
}

int	print_u(va_list *args)
{
	return (ft_putnbr(va_arg(*args, unsigned int)));
}

