/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:45:22 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/11 09:35:57 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	int	total_len;
	va_list args;
	unsigned int	i;
	int	(*f[256])(va_list *);

	i = 0;
	while (i < 256)
	{
		f[i] = NULL;
		i++;
	}
	f['c'] = ft_print_char;
	f['s'] = ft_print_string;
	f['p'] = ft_print_address;
	f['d'] = ft_print_decimal;
	f['i'] = ft_print_decimal;
	f['u'] = ft_print_unsigned_decimal;
	f['x'] = ft_print_lower_hex;
	f['X'] = ft_print_upper_hex;
	va_start(args, s);
	i = 0;
	total_len = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '\0')
				return (-1);
			if (s[i] == '%')
				total_len = total_len + write(1, "%", 1);
			else if (f[(unsigned char)s[i]] != NULL)
				total_len = total_len + f[(unsigned char)s[i]](&args);
			else
			{
				total_len = total_len + write(1, "%", 1);
				total_len = total_len + write(1, &s[i], 1);
			}
		}
		else
			total_len = total_len + write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (total_len);
}
