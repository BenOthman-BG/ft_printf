/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:27:21 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/12 13:59:32 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

typedef int (*t_printer)(va_list *);

int	ft_printf(const char *s, ...);
void	dispatch_table(t_printer *table);

int	print_c(va_list *args);
int	print_s(va_list *args);
int	print_pct(va_list *args);

int	print_d(va_list *args);
int	print_u(va_list *args);

int	print_addr(va_list *args);
int	print_lower_x(va_list *args);
int	print_upper_x(va_list *args);

#endif
