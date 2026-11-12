/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:13:22 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 14:00:17 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_table(t_printer *table)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		f[i] = NULL;
		i++;
	}
	table['c'] = ft_print_c;
	table['s'] = ft_print_s;
	table['p'] = ft_print_addr;
	table['d'] = ft_print_d;
	table['i'] = ft_print_d;
	table['u'] = ft_print_u;
	table['x'] = ft_print_lower_x;
	table['X'] = ft_print_upper_x;
	table['%'] = ft_print_pct;
}
