/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:45:22 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:16:53 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	int	total_len;
	va_list args;
	int	i;
	int	(*f[256])(va_list *);

	f['c'] = ft_print_char;
	f['s'] = ft_print_string;
	f['p'] = ft_print_adress;
	f['d'] = ft_print_decimal;
	f['i'] = ft_print_decimal;
	f['u'] = ft_print_unsigned_decimal;
	f['x'] = ft_print_lower_hex;
	f['X'] = ft_print_upper_hex;
	f['%'] = ft_print_char;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			total_len = total_len + f[s[i + 1]](&args);
		else
			total_len = total_len + f[s[i]];
		i++;
	}
	return (total_len);
}
