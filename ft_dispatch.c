/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:13:22 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 14:07:47 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_table(t_printer *table)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		table[i] = NULL;
		i++;
	}
	table['c'] = print_c;
	table['s'] = print_s;
	table['p'] = print_addr;
	table['d'] = print_d;
	table['i'] = print_d;
	table['u'] = print_u;
	table['x'] = print_lower_x;
	table['X'] = print_upper_x;
	table['%'] = print_pct;
}
