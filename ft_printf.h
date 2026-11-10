/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:27:21 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/10 18:27:22 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *s, ...);
void	ft_print_char(va_list *args);
void	ft_print_string(va_list *args);
void	ft_print_addres(va_list *args);
void	ft_print_decimal(va_list *args);
void	ft_print_unsigned_decimal(va_list *args);
void	ft_print_lower_hex(va_list *args);
void	ft_print_upper_hex(va_list *args);

#endif
