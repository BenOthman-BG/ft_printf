/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 08:45:22 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 14:01:52 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_help(char const *s, va_list *args, t_printer *table)
{
	int	i;
	int	count;
	int	tmp;
	
	i = -1;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		if (s[i] == '%' && table[(unsigned char)s[i + 1]])
			tmp = table[(unsigned char)s[++i]](args);
		else
			tmp = write(1, &s[i], 1);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	return (count);
}

int	ft_printf(char const *s, ...)
{
	int	count;
	va_list args;
	t_printer table[256];

	if (!s)
		return (-1);
	dispatch_table(table);
	va_start(args, s);
	count = ft_help(s, &args, table);
	return (va_end(args), count);
}
